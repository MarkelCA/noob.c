#include <stdio.h>
#include <string.h>


size_t strSize(char * pStr) {
    return (strlen(pStr) * sizeof(*pStr)) + 1; // We sum 1 because of the null character 
}
size_t intArSize(int * pInt) {
    printf("My num pointer %p:\n", pInt);
    printf("My num pointer + 1 %p:\n", pInt + 1);

    printf("The value of the pointer + 1: %d\n", *(pInt + 1));

    return 0;
}

// Official strcat (from https://www.joelonsoftware.com/2001/12/11/back-to-basics/)
void mystrcat2( char* dest, char* src )
{
    while (*dest) dest++;
    while ((*dest++ = *src++));
}
// This is a clone to understand strcat
void mystrcat(char * dest, const char * src) {
    while (*dest){
        /*printf("%c", *dest);*/
        dest++;
    };

    *dest = *src;
    while (*src){
        dest++;
        src++;
        *dest = *src;
    };
    
    /*printf("dest: %s\n", dest);*/
}
char* efficient_mystrcat( char* dest, char* src )
{
    while (*dest) dest++;
    while ((*dest++ = *src++));
    return --dest;
}

int main () {

    char str[] = "A new string";
    char * pStr = str;
    /*printf("%c", *pStr);*/
    /*printf("%lu\n", strlen(str));*/

    fputs("Write a string pls: ", stdout);
    scanf("%s", str);

    printf("\nYour string is: \"%s\" and its lenght is %lu\n", str, strlen(str));
    printf("The pointer value is: \"%s\" and its lenght is %zu\n", pStr, strlen(pStr) );


    printf("The size of the string \"%s\" is: %zu\n", pStr, strSize(str) );

    //INT
    int nums[] = {11,22,33};
    int * pNums = nums;

    printf("My array length is: %zu\n", intArSize(nums));

    puts("------------------------");
    puts("String concatenating");
    char s1[] = "ab";
    mystrcat(s1, "12");
    mystrcat(s1, "12");
    mystrcat(s1, "12");
    puts(s1);
    char s2[] = "probando";
    mystrcat2(s2, " mystrcat");
    puts(s2);
    int a = 0;


    // This way I'm  smashing the stack, because of index overflow
    //char s3[] = "This"; // I don't know how much memory allocate
    //char *p = s3;
    //p = efficient_mystrcat(p, " is the final one :)");
    //p = efficient_mystrcat(p, " and its the fastest");
    //puts(s3);

    // Works this way
    char s3[1000];  // I don't know how much memory allocate;
    char *p = s3;
    s3[0] = '\0';
    p = efficient_mystrcat(p, "This is the final one");
    p = efficient_mystrcat(p, " and it's the fastest :)");
    puts("");
    puts(s3);


    return 0;
}
