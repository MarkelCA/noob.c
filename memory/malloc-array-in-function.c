#include <stddef.h>
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
    printf("Created a %d int index array", length);
}
void print_array(int * array, int length)
{
    printf("The elements of the array are: ");
    for (int i = 0; i < length; ++i) {
        printf("%d, ",array[i]);
    }

}
void print_memory_used (long int size_bytes) 
{
    float size_kb = size_bytes * 9.77 * pow(10, -4);
    if(size_kb >= 1) {
        double size_mb = size_bytes * 9.537 * pow(10, -7);
        if(size_mb >= 1) 
            printf("Size allocated: %.2f MB\n", size_mb);
        else 
        printf("Size allocated: %.2f KB\n", size_kb);
        
    }
    else 
        printf("Size allocated: %lu B\n", size_bytes);
    

}
int main()
{
	// This pointer will hold the base address of the block created
	long int  arr_length = 1000000000; // A pretty big array
    long int size_bytes = arr_length * sizeof(int);

	int* nums = create_array_pointer(arr_length);

	if (nums == NULL) 
		exit(0);

    fill_array(nums, arr_length);
    puts("");
    print_memory_used(size_bytes);
    free(nums);
    puts("End of the program");
	return 0;
}
