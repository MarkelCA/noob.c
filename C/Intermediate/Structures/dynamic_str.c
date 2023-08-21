#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 5
#define BUFFER_SIZE 100

typedef struct {
    char **data;
    size_t size;
    size_t capacity;
} StringList;

void initStringList(StringList *list) {
    list->data = (char **)malloc(INITIAL_CAPACITY * sizeof(char *));
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
}

void addString(StringList *list, const char *str) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (char **)realloc(list->data, list->capacity * sizeof(char *));
    }
    
    list->data[list->size] = (char *)malloc(strlen(str) + 1);
    strcpy(list->data[list->size], str);
    list->size++;
}

void freeStringList(StringList *list) {
    for (size_t i = 0; i < list->size; i++) {
        free(list->data[i]);
    }
    free(list->data);
    list->size = 0;
    list->capacity = 0;
}

int main() {
    StringList myList;
    initStringList(&myList);

    char buffer[BUFFER_SIZE];
    while (1) {
        printf("Enter a string (or type 'exit' to quit): ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
        
        if (strcmp(buffer, "exit") == 0) {
            break;
        }
        
        addString(&myList, buffer);
    }

    for (size_t i = 0; i < myList.size; i++) {
        printf("String %zu: %s\n", i + 1, myList.data[i]);
    }

    freeStringList(&myList);

    return 0;
}

