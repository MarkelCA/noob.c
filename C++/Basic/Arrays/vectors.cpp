#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec = {1,2, 3, 4, 5, 6, 7, 8};
    for (auto i = vec.begin(); i != vec.end(); ++i)
        cout << *i << "\t";
    return 0;
}
