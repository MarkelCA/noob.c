
#include <cstdio>
#include <iostream>
#include <math.h>       
//#include <sstream>

using namespace std;

int main() {
    //int number = 5;
    int n2 = 2;
    cout << &n2 << "\n";
    //int * myPointer = &number;
    int * anotherPointer = &n2;

    //string name = "Markel"; 
    //string * namePointer = &name;
    //*anotherPointer = 12;
    int n = 12;
    *anotherPointer = 4;

    //cout << "My pointer: " << myPointer << "\n";
    cout << "Another pointer: " << *anotherPointer << "\n";
    cout << "Another pointer: " << anotherPointer << "\n";
    cout << "The pointer: " << &n2 << "\n";
    cout << (anotherPointer == &n2 ? "AnotherPointer and n2 ARE the same" : " Another pointer and n2 ARE NOT the same") << "\n";
    cout << "n2 value: " << n2;


    int i = 2;
    int *pi = &i;
    int **ppi = &pi;
    int ***pppi = &ppi;
    int ****ppppi = &pppi;

    cout << i << "\n";
    cout << pi << "\n";
    cout << ppi << "\n";
    cout << pppi << "\n";
    cout << ppppi << "\n";
    return 0;
}
