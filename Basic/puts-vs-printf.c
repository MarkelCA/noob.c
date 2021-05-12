#include <stdio.h>
int main() 
{
    char movie [20];
    char *pMovie = movie;

    /*fgets(pMovie, 20, stdin);*/
    int n = 10;
    float m = 10;
    // A formated print with
    printf("My number int: %d\nMy number float: %f\n", n, m);

    // A literal print with a linebreak
    puts("ka%dlfj");
    // fputs with the stdout prints with no line break
    fputs("ka%dlfj", stdout);
    puts("1345678");
    return 0;
}
