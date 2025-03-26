#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "DataStore.h"

#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];

    while (1) {
	memset(buffer, 0, BUFFER_SIZE);
	int bytes_read = read(client_socket, buffer, BUFFER_SIZE - 1);

	if (bytes_read <= 0) {
	    printf("Client disconnected.\n");
	    close(client_socket);
	    return;
	}

    buffer[bytes_read] = '\0';
    printf("Received: %s", buffer);
    
    char key[50];
    char value[100];
    int expiry;

    if (sscanf(buffer, "SET %s %s %d", key, value, &expiry) == 3) {
            set(key, value, expiry);
            write(client_socket, "+OK\r\n", 5);
        } else if (sscanf(buffer, "GET %s", key) == 1) {
            const char *result = get(key);
            write(client_socket, result, strlen(result));
        } else if (sscanf(buffer, "DEL %s", key) == 1) {
            del(key);
            write(client_socket, "+OK\r\n", 5); 
        }
    }
}

int start_server(int port) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        return -1;
    }

    listen(server_socket, 5);

    printf("Server listening on port %d...\n", port);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket >= 0) {
            handle_client(client_socket);
        }
    }

    close(server_socket);
    return 0;
}

