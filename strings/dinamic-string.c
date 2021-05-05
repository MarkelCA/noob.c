#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE_STR 10 * 256

int * fill_str_pointer(char * str, unsigned int length) {
    fputs("Write a text please: ",stdout);
    fgets(str, length , stdin);

    printf("%s - length: %lu",str, strlen(str));
    return 0;
}

char * allocate_memory(size_t size) {
    char * str = malloc(size);
    if(str == NULL) {
        puts("No memory avaliable");
        exit(0);
    }

    return str;
}
int main() {
    /*printf("%d", MAX_SIZE_STR);*/
    char * mystr = allocate_memory(MAX_SIZE_STR);
    fill_str_pointer(mystr, MAX_SIZE_STR);

    return 0;
}
