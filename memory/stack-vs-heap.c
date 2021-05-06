#include <stdio.h>

    int g1;
int main()
{
    int i1;
    int i2;

    static int s1;
    static int s2 = 1;

    static int * h1;
    static int * h2;
    static int * h3;

    struct Point {
       int x;
       int y;
    };
     
    struct Point p1;
    struct Point p2;

    printf("Pointer of point 2:  %p\tStack\n", &p2); // Stack
    printf("Pointer of point 1:  %p\tStack\n", &p1); // Stack

    printf("\nPointer of int 2:    %p\tStack\n", &i2); // Stack
    printf("Pointer of int 1:    %p\tStack\n", &i1); // Stack

    printf("\nPointer of h1:       %p\tHeap\n", &h1); // Heap
    printf("Pointer of h2:       %p\tHeap\n", &h2); // Heap
    printf("Pointer of h3:       %p\tHeap\n", &h3); // Heap

    printf("\nPointer of global 1: %p\tBSS\n", &g1); // Unitialized (BSS)
    printf("Pointer of static 1: %p\tBSS\n", &s1); // Unitialized (BSS)

    printf("\nPointer of static 2: %p\tData\n", &s2); // Initialized

    puts("\nConclusion:\n------------------------");
    puts("Stack:");
    puts("\t-Pointers:  Ascending 8 sized interval because of the pointer size");
    puts("\t-Ints:      Ascending 4 sized interval");

    puts("Heap:");
    puts("\t-Pointers:  Descending 8 sized interval because of the pointer size");


    puts("BSS:");
    puts("\t-Global:    Descending 4 sized interval");
    puts("\t-Static:    Descending 4 sized interval");

return 0;
}
