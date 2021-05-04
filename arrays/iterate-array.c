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

    puts("Array 2 with size");
    int arr2[SIZE] = { 1, 2, 3, 4, 5 };
    for (int i = 0;i < SIZE ; i++) {
      printf("%u\t", arr2[i]);
    }


    /*puts("Array 3 with size");*/
    /*int SIZE2 = 2;*/
    /*int arr3[SIZE2] = { 1, 2 };*/
    /*for (int i = 0;i < SIZE2 ; i++) {*/
      /*printf("%u\t", arr3[i]);*/
    /*}*/


    fun(6);
return 0;
}
