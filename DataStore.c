#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEYS 100

typedef struct {
	char key [50];
	char value[100];
	time_t expiry;
} KeyValue;

keyValue store[MAX_KEYS];

void set(const char *key, const char *value, int expiry) {
	for (int i = 0; i < MAX_KEYS; i++) {
		if (strlen(store[i] == 0) {
			strcpy(store[i].key, key);
			strcpy(store[i].value, value);
			store[i].expiry = expiry > 0 ? time(NULL) + expiry : 0;
			printf("OK\n");
			return;
		}
	}
	printf("ERROR: Store is full\n")
}

const char *get(const char *key) {
    for (int i = 0; i < MAX_KEYS; i++) {
        if (strcmp(store[i].key, key) == 0) {
            if (store[i].expiry != 0 && time(NULL) > store[i].expiry) {

                strcpy(store[i].key, "");
                return "(nil)"; 
            }
            return store[i].value;
        }
    }
    return "(nil)";
}


void del(const char *key) {
    for (int i = 0; i < MAX_KEYS; i++) {
        if (strcmp(store[i].key, key) == 0) {
            strcpy(store[i].key, "");
            printf("OK\n");
            return;
        }
    }
    printf("ERROR: Key not found\n");
}







