#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
  int x;
  int y;
  int area;
}point;

struct Point *new_Point(int x, int y);
int getArea(point *p);
void setArea(point *p);
void displayPointInfo(point *p);

int main()
{
   printf("\nPoint 1\n--------------\n");
   point *p1 = new_Point(2, 2);
   displayPointInfo(p1);

   printf("\n\nPoint 2\n--------------\n");
   point *p2 = new_Point(28, 45);
   displayPointInfo(p2);

   return 0;
}

point * new_Point(int x, int y)
{
   point *p = malloc(sizeof(*p));
   p->x = x;
   p->y = y;
   setArea(p);
   return p;
}
void displayPointInfo(point *p){
   printf("x: %d\n", p->x);
   printf("y: %d\n", p->y);
   printf("Area: %d", p->area);
}
void setArea(point *p) {
    p->area = p->x * p->y;
}

int getArea(point *p){
    return p->area;
}
