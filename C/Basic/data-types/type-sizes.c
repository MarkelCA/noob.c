#include "<iostream>"
using namespace std;

int a[3] = {1, 2, 3};
int b[4] = {4, 5, 6, 7};
int c[3] = {};

int * a2 = a;
int * matrix[] = {a, b};

int x = 2;
float y = 2.2;
double z = 2;
int main() {

    // Simple variable sizes
    cout << "------------------------------------\n";
    cout << "Simple variable sizes\n\n";
    cout << "Int has a size of:" << sizeof(x) << "\n";
    cout << "Float has a size of: " << sizeof(y) << "\n";
    cout << "Double has a size of: " << sizeof(z) << "\n";
    cout << "A has a value of: " << sizeof(a) << "\n";
    cout << "B has a value of: " << sizeof(b) << "\n";
    cout << "C has a size of: " << sizeof(c) << "\n";
    cout << "------------------------------------\n";
     //THE SIZE OF A POINTER WILL IN EVERY 64 BITS COMPUTER BE 8 BYTES
    cout << "THE SIZE OF A POINTER WILL IN EVERY 64 BITS COMPUTER BE 8 BYTES";
    cout << "\nMatrix[0] has a size of: " << sizeof(matrix[0]) << "\n";
    cout << "Matrix[0] has a type of: " << typeid(matrix[1]).name() << "(Pointer int)\n";
    cout << "Matrix has a size of: " << sizeof(matrix) << "\n";
    cout << "------------------------------------\n";
    cout << "matrix[0] value: " << matrix[0] << " - type: " << typeid(matrix[0]).name() << "\n";
    cout << "matrix[0] pointer value: " << *matrix[0] << " - type: " << typeid(*matrix[0]).name() << "\n" ;
    cout << "Value of matrix[0][2]: " << matrix[0][2] << " - type: " << typeid(matrix[0][0]).name() << "\n" ;
    cout << "a == *&matrix[0] = " << ( a == *&matrix[0]) << "\n";


    return 0;
}
