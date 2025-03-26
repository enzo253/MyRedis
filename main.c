#include <stdio.h>
#include <stdlib.h>
#include "server.h"

int main() {
    printf("Starting Redis-like server...\n");

    if (start_server(6379) != 0) {
        fprintf(stderr, "Failed to start server.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
