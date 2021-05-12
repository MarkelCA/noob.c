#include <stdio.h>

    int g1;
    int g2 = 2;
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

    printf("Point 2:          %p\tStack\n", &p2); // Stack
    printf("Point 1:          %p\tStack\n", &p1); // Stack

    printf("\nInt 2:            %p\tStack\n", &i2); // Stack
    printf("Int 1:            %p\tStack\n", &i1); // Stack

    printf("\nPointer of h1:    %p\tHeap\n", &h1); // Heap
    printf("Pointer of h2:    %p\tHeap\n", &h2); // Heap
    printf("Pointer of h3:    %p\tHeap\n", &h3); // Heap

    printf("\nGlobal 1:         %p\tBSS\n", &g1); // Unitialized (BSS)
    printf("Static 1:         %p\tBSS\n", &s1); // Unitialized (BSS)

    printf("\nStatic 2:         %p\tData\n", &s2); // Initialized
    printf("Global 2:         %p\tData\n", &g2); // Initialized

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
