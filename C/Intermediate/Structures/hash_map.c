#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 100

typedef struct HashMap {
    char *key;
    char *value;
    struct HashMap *next;
} HashMap;

unsigned int hash_function(const char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash << 5) + *key++;
    }
    return hash % HASH_TABLE_SIZE;
}

HashMap *create_hash_map(const char *key, const char *value) {
    HashMap *hm = (HashMap *)malloc(sizeof(HashMap));
    hm->key = strdup(key);
    hm->value = strdup(value);
    hm->next = NULL;
    return hm;
}

void insert_hash_map(HashMap *buckets[], const char *key, const char *value) {
    unsigned int index = hash_function(key);
    HashMap *hm = create_hash_map(key, value);

    if (buckets[index] == NULL) {
        buckets[index] = hm;
    } else {
        HashMap *current = buckets[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = hm;
    }
}

const char *get_value(HashMap *buckets[], const char *key) {
    unsigned int index = hash_function(key);
    HashMap *current = buckets[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }

    return NULL;
}

void free_hash_map(HashMap *buckets[]) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        HashMap *current = buckets[i];
        while (current != NULL) {
            HashMap *temp = current;
            current = current->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
}

int main() {
    HashMap *hash_map[HASH_TABLE_SIZE] = { NULL };

    insert_hash_map(hash_map, "foo", "bar");
    insert_hash_map(hash_map, "fizz", "buzz");
    insert_hash_map(hash_map, "x", "y");

    printf("foo: %s\n", get_value(hash_map, "foo"));
    printf("fizz: %s\n", get_value(hash_map, "fizz"));
    printf("x: %s\n", get_value(hash_map, "x"));

    free_hash_map(hash_map);

    return 0;
}
