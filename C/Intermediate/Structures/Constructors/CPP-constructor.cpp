#include <iostream>
class A {
  public:
    A() { a = 0; }
    int a;
};

int main() 
{
  A b;
  A *c = new A;
  return 0;


   printf("%d\n", c->a);
}
