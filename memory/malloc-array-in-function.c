#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int * create_array_pointer(int length) {
	// Dynamically allocate memory using malloc()
	return (int*)malloc(length * sizeof(int));
}
void fill_array(int * array, int length) {
    for (int i = 0; i < length; ++i) {
        array[i] = i + 1;
    }
    printf("Created a %d index array", length);
}
void print_array(int * array, int length){
    printf("The elements of the array are: ");
    for (int i = 0; i < length; ++i) {
        printf("%d, ",array[i]);
    }

}
int main()
{
	// This pointer will hold the base address of the block created
	long int  arr_length = 1000000000; // A pretty big array
    long int size_bytes = arr_length * sizeof(int);
    size_t size_mb = size_bytes * pow(10, -6);

	int* nums = create_array_pointer(arr_length);

	if (nums == NULL) {
		exit(0);
	}
	else {
        fill_array(nums, arr_length);
        puts("");
        printf("Size allocated: %lu MB\n", size_mb);
	}

    puts("End of the program");
	return 0;
}
