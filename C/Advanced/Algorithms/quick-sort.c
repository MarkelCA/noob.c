// simple C program for Quick Sort
#include <stdio.h>

int partition(int a[], int beg, int end);  
void quickSort(int a[], int beg, int end);  
void printArray(int ar[], int size);
int main()  
{  
    /*int arr[10]={90,23,101,45,65,28,67,89,34,29};  */
    int arr[10]={9,7,5,11,12,2,14,3,10, 6};  
    quickSort(arr, 0, 9);  
    printf("\n The sorted array is: \n");  
return 0;
}  
void printArray(int arr[], int size){
    printf("{ ");
    for(int i=0;i<size;i++)  {
        char * coma = i < size - 1 ? ", " : "";
        printf("%d%s", arr[i], coma);  
    }
    printf(" }");
}
int partition(int a[], int beg, int end)  
{  
    int left, right, temp, loc, flag;     
    loc = left = beg;  
    right = end;  
    flag = 0;  
    while(flag != 1)  
    {  
        while((a[loc] <= a[right]) && (loc!=right))  
            right--;  
        if(loc==right)  
        flag =1;  
        else if(a[loc]>a[right])  
        {  
            temp = a[loc];  
            a[loc] = a[right];  
            a[right] = temp;  
            loc = right;  
        }  
        if(flag!=1)  
        {  
            while((a[loc] >= a[left]) && (loc!=left))  
                left++;  
            if(loc==left)  
            flag =1;  
            else if(a[loc] < a[left])  
            {  
                temp = a[loc];  
                a[loc] = a[left];  
                a[left] = temp;  
                loc = left;  
            }  
        }  
    }  
    return loc;  
}  
void quickSort(int a[], int beg, int end)  
{  
    int loc;  
    if(beg > end) return;
     
    // if beginning < end
    //
    printArray(a, 10);
    puts("\n");
    loc = partition(a, beg, end);  
    quickSort(a, beg, loc-1);  
    quickSort(a, loc+1, end);  
      
}  
