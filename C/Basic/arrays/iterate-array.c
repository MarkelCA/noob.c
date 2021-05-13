#include <stddef.h>
#include <stdio.h>
#define SIZE (6)

void fun(int n) {
    int arr[n];
}

int main() {

    int arr[5] = { 1, 2, 3, 4, 5 };

    for (int i = 0; i < 5; i++) {
      printf("%u\n", arr[i]);
    }

    int n = 0;
    printf("\nEnter a size pls: ");
    scanf("%d", &n);
    int myAr[n];
    myAr[0] = 12;
    myAr[1] = 13;
    myAr[2] = 53;
    myAr[30] = 66666;
    puts("\ntesting array adresses");
    printf("%p\n", &myAr[0]);
    printf("%p\n", &myAr[1]);
    printf("%p\n", &myAr[2]);

    puts("\nArray of input long\n");

    for (int i = 0;i < n ; i++) {
      printf("%u\t", myAr[i]);
    }

    puts("Array 2 with size");
    int arr2[SIZE] = { 1, 2, 3, 4, 5 };
    for (int i = 0;i < SIZE ; i++) {
      printf("%u\t", arr2[i]);
    }

    puts("");
    int arr3[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    for (int  * i = arr3; i < &arr3[10]; i++) {
        printf("%p\t", i);
    }

    puts("");

    enum sizes { arr1 = 255 };
    enum sizes a1Size = arr1;
    char buf[a1Size + 1];
    buf[0] = 'a';
    buf[1] = 'a';

    printf("%d", arr1);



return 0;
}
