#include <stdio.h>
#include <string.h>
int main() 
{
    int i1 = 0, i2 = 0;
    char s1[30] = {'a'}, s2[30] = {0};
     
    /*scanf("%d", &i1);*/
    scanf("%d", &i2);

    fgets(s1,30, stdin);
    /*fgets(s2,30, stdin);*/

    puts("--------------------");
    /*printf("i1: %d\n", i1);*/
    printf("i2: %d\n", i2);
    printf("s1: %s\n", s1);
    /*printf("s2: %s\n", s2);*/
}
