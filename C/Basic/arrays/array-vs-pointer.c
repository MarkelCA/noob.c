// 1st program to show that array and pointers are different
#include <stdio.h>

int main()
{
	int arr[] = { 10, 20, 30, 40, 50, 60 };
	char str[] = "This is my string";
	int nums[] = {1,2,3,4};
	int* ptr = arr;

	// sizof(int) * (number of element in arr[]) is printed
	printf("Size of arr[] %ld\n", sizeof(arr));

	// sizeof a pointer is printed which is same for all
	// type of pointers (char *, void *, etc)
	printf("Size of ptr %ld\n", sizeof(ptr));

    printf("%p\n", arr);
    printf("%p\n", arr+1);
    printf("%p\n", &arr[1]);

    printf("%p\n", str);
    printf("%p\n", str+1);

    printf("%p\n", nums);
    printf("Espacio de memoria %p: %d\n", nums+3, *(nums+3));
    printf("Espacio de memoria %p: %d\n", nums+5, *(nums+5));

    printf("Espacio entre nums3 y nums5: %ld\n", (nums+5) - (nums+3));
    printf("%p + %d = %p", nums+3, 2, nums+3+2);


	return 0;
}
