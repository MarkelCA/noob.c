#include <stdio.h>
#include <string.h>

int main() {
    char c = 'c';
    char str[] = "";
    /*printf("%zu\n", sizeof(c));*/
    /*printf("%zu\n", sizeof(str));*/
    /*if(sizeof(c) == sizeof(str))*/
        /*puts("Null bytes takes 1 byte of memory");*/
    /*puts(get);*/

    char charStr[] = {'c', 'b', '\0'};
    char charAr[] = {'a', 'b'};
    char charStr2[] = {"123"};
    /*char c2 = "c";*/
    char c3 = '\0';

    char c4[] = {'\0', '2'};
    /*printf("%c", c2);*/
    /*printf("%d", c2);*/

    /*printf("%d", strlen(c3));*/
    /*printf("%lu", strlen(str));*/
    printf("%lu", strlen(c4));
    /*printf("%lu", strlen(charStr));*/
    printf("%s\n", charStr);
    printf("%s - CharStr length: ", charStr2);
    printf("%zu\n", strlen(charStr2));

    printf("CharAr: %s\n", charAr);
    printf("CharAr Length: %zu\n", strlen(charAr));

    printf("CharStr: %s\n", charStr);
    printf("CharStr Length: %zu\n", strlen(charStr));

    char new[] = {};
    char jeje[] = "";

    printf("|%d|\n", (int)(new[0]));
    printf("|%s%s|\n", new, jeje);

    char * pc = "12345";
    printf("%s\n", pc);
    pc = "123456789";
    printf("%s\n", pc);

    return 0;
}
