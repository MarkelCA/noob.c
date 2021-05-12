// A variable declaration with structure declaration.
#include <stdio.h>
struct Point
{
int x, y;
};

struct myStructure {
    int x;
    char * str;
    double d;
};

int main()
{
struct Point p1; // The variable p1 is declared like a normal variable


struct myStructure mS1= {1, "myString", 2};
struct myStructure mS2 = {.d = 4.2, .x=59, .str="ms2 string"};
printf("mS1 str = \"%s\"\n", mS1.str);
printf("mS2 double = %f\n", mS2.d);
printf("mS2 int = %d\n", mS2.x);
printf("mS2 string = \"%s\"\n", mS2.str);
return 0;
}
