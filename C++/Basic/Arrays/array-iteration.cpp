#include <cstdio>
#include <iostream>

int main() {

    puts("Iteratng an array with a for loop");
    int arr[5] = { 1, 2, 3, 4, 5 };

    for (int i = 0; i < 5; i++) 
      printf("%u\t", arr[i]);
    

    puts("");
    puts("\n I can also iterate an array with a foreach");
    int arr4[10] = {11, 7, 9, 78, 100, 55, 43, 33, 2, 15};

    for(int x:arr4) 
        printf("%d\t", x);


    return 0;
}
