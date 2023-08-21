#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 100

typedef struct KeyValue {
    char *key;
    char *value;
    struct KeyValue *next;
} KeyValue;

typedef struct {
    KeyValue *buckets[HASH_TABLE_SIZE];
} HashMap;

unsigned int hashFunction(const char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash << 5) + *key++;
    }
    return hash % HASH_TABLE_SIZE;
}

KeyValue *createKeyValue(const char *key, const char *value) {
    KeyValue *kv = (KeyValue *)malloc(sizeof(KeyValue));
    kv->key = strdup(key);
    kv->value = strdup(value);
    kv->next = NULL;
    return kv;
}

void insertKeyValue(HashMap *map, const char *key, const char *value) {
    unsigned int index = hashFunction(key);
    KeyValue *kv = createKeyValue(key, value);

    if (map->buckets[index] == NULL) {
        map->buckets[index] = kv;
    } else {
        KeyValue *current = map->buckets[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = kv;
    }
}

const char *getValue(HashMap *map, const char *key) {
    unsigned int index = hashFunction(key);
    KeyValue *current = map->buckets[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }

    return NULL;
}

void freeHashMap(HashMap *map) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        KeyValue *current = map->buckets[i];
        while (current != NULL) {
            KeyValue *temp = current;
            current = current->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
}

int main() {
    HashMap myMap;
    memset(&myMap, 0, sizeof(HashMap));

    insertKeyValue(&myMap, "name", "John");
    insertKeyValue(&myMap, "age", "30");
    insertKeyValue(&myMap, "city", "New York");

    printf("Name: %s\n", getValue(&myMap, "name"));
    printf("Age: %s\n", getValue(&myMap, "age"));
    printf("City: %s\n", getValue(&myMap, "city"));

    freeHashMap(&myMap);

    return 0;
}
