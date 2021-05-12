#include <cstdio>
#include <iostream>

// A variable declaration with structure declaration.
struct Point
{
int x, y;
int sum(int x, int y){
    return x+y;
}

} p1; // The variable p1 is declared with 'Point'


// A variable declaration like basic data types

int main()
{
    struct Point p2;
    Point p3 = {0, 1};
    std::cout << p3.sum(p3.x, p3.y) << "\n";
    p2.x = 1;
    p2.y = 1;
    std::cout << p2.sum(p2.x, p2.y) << "\n";
    //struct Point p1; // The variable p1 is declared like a normal variable
    std::cout << p1.x;
}
