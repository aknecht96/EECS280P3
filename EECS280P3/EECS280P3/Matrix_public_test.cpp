#include "Matrix.h"
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

// This file tests VERY FEW of the expected behaviors of the Matrix module.
// It will only really tell you if your code compiles. You must write
// your own comprehensive unit tests!

int main() {
    Matrix m;
    Matrix *p = &m;
    Matrix_init(p, 1, 1);
    assert(Matrix_size(p) == 1);
    assert(Matrix_num_rows(p) == 1);
    assert(Matrix_num_columns(p) == 1);

    char* c_ptr = Matrix_at(p, 0, 0);
    *c_ptr = 'x';
    assert(*Matrix_at(p, 0, 0) == 'x');

    assert(Matrix_row(p, c_ptr) == 0);
    assert(Matrix_col(p, c_ptr) == 0);

    Matrix_print(p);

    char buffer[10];
    int buffer_size = 0;
    Matrix_range_radius(p, 0, 0, 0, buffer, &buffer_size);
    assert(buffer_size == 1);
    assert(buffer[0] == 'x');

    assert(Matrix_search_simple(p, 'x') == c_ptr);
    assert(Matrix_search_random(p, 'x') == c_ptr);

    cout << "Matrix_public_tests passed" << endl;
    return 0;
}
