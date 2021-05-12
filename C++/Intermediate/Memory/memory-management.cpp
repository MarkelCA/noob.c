// Following this video https://www.youtube.com/watch?v=vvgKqoKa8Mg&t=115s
#include <exception>
#include <iostream>
#include <memory>
using namespace std;

struct OwningInt {
    OwningInt()
        : mPtr(new int)
    {
    }
    ~OwningInt()
    {
        cout << "dtor\n";
        delete mPtr;
    }
    int *mPtr;
};
// Raw pointers are BAD
// What can we say about this pointer
// Who owns it? We don't know
// Caller? We dont' know
// From the raw pointes we can's know anything
void f(int *) {

}

void g(const OwningInt &arg) {
    try {

    OwningInt someInt;
    throw exception();
    }
    catch (...)
    {

    }
}

int main() {
    g(OwningInt());

    return 0;
}
