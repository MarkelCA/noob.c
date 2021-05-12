#include<stdio.h>

struct Point
{
int x, y;
};

int main()
{
// Create an array of structures
struct Point arr[10];

// Access array members
arr[0].x = 10;
arr[0].y = 20;

printf("%d %d", arr[0].x, arr[0].y);
return 0;
}
