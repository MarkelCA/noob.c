#include "iostream"
#include <bits/stdc++.h>

using namespace std;

template <typename T, size_t N>
using matrix_t = array<array<T, N>, N>;

template <typename T, size_t N>
void proc (matrix_t<T, N> &matrix) {
    matrix[N - 1][N - 1] = 7;
}

int main () {
    matrix_t<int, 10> matrix;
    proc(matrix);
}
