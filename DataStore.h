#ifndef DATASTORE_H
#define DATASTORE_H

void set(const char *key, const char *value, int expiry);
const char *get(const char *key);
void del(const char *key);

#endif

