#include "iostream"
#include <bits/stdc++.h>

using namespace std;

int a[] = {1, 2, 3};
int b[] = {4, 5, 6};
int * mat[] = {a, b};

int mat2[2][2] = {
    {},
    {}
};

int mat3[2][2] = {
    1,2,
    3,4
};

int mat4[3][6] {
    0,1,2,3,4,5,6,
    7,8,9,10,11,12,
    13,14,15,16,17,
};


int array_length (int *arr) {
    //cout << arr << "\n";
    //cout << arr[0] << "\n";
    cout << arr << "\n";
    cout << arr+1 << "\n";
    //cout << &arr << "\n";
    cout << *(arr + 1) - *arr << "\n";
    return 0;
}

int array_length2 (int& arr) {
    return sizeof(arr);
}
int main() {
    int ar[] = {1,2, 3};
    //cout << array_length2(ar); 
    return 0;
}
