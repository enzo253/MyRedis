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







