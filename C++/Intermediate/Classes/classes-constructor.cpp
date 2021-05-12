// C++ program to demonstrate constructors

#include <bits/stdc++.h>
using namespace std;
class Geeks
{
	public:
	int id;
    string param2;

	//Default Constructor
	Geeks()
	{
		cout << "Default Constructor called" << endl;
		id=-1;
	}
	
	//Parametrized Constructor
	Geeks(int x, string param)
	{
		cout << "Parametrized Constructor called" << endl;
        param2 = param;
		id=x;
	}
};
// FROM: https://docs.microsoft.com/es-es/cpp/cpp/constructors-cpp?view=msvc-160
class Box {
public:
    // Default constructor
    Box() {}

    // Initialize a Box with equal dimensions (i.e. a cube)
    explicit Box(int i) : m_width(i), m_length(i), m_height(i) // member init list
    {}

    // Initialize a Box with custom dimensions
    Box(int width, int length, int height)
        : m_width(width), m_length(length), m_height(height)
    {}

    int Volume() { return m_width * m_length * m_height; }

private:
    // Will have value of 0 when default constructor is called.
    // If we didn't zero-init here, default constructor would
    // leave them uninitialized with garbage values.
    int m_width { 0 };
    int m_length{ 0 };
    int m_height{ 0 };
};
int main() {
	
	// obj1 will call Default Constructor
	Geeks obj1;
	cout << "Geek id is: " <<obj1.id << endl;
	
	// obj1 will call Parametrized Constructor
	Geeks obj2(21, "myparam");
	cout << "Geek id is: " <<obj2.id << endl;
    cout << "Param2: " << obj2.param2 << "\n";


    Box b; // Calls Box()

    // Using uniform initialization (preferred):
    Box b2 {5}; // Calls Box(int)
    Box b3 {5, 8, 12}; // Calls Box(int, int, int)

    // Using function-style notation:
    Box b4(2, 4, 6); // Calls Box(int, int, int)
    cout << b.Volume();
	return 0;
}
