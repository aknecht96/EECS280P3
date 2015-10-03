#include "Matrix.h"
#include <iostream>
#include <cassert>
using namespace std;

void test_minimum_size_matrix();

// ADD PROTOTYPES FOR YOU TEST FUNCTIONS HERE

int main() {

  test_minimum_size_matrix();

  // CALL YOUR TEST FUNCTIONS HERE

  cout << "Matrix_tests passed" << endl;
  return 0;
}

void test_minimum_size_matrix() {
  Matrix matrix;
  Matrix *ptr = &matrix;
  Matrix_init(ptr, 0, 0);
  assert(Matrix_size(ptr) == 0);
}

// IMPLEMENT YOUR TEST FUNCTIONS HERE
