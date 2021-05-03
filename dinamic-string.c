#include <stdio.h>
#include <string.h>

int main () {

    char * str;
    str = "A new string";
    printf("%lu\n", strlen(str));
    str = "123";
    scanf("%s", str);
    printf("%s\n", str);
    printf("%lu\n", strlen(str));
    return 0;
}
