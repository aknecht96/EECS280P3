#include "util.h"
#include <cassert>
#include <iostream>
using namespace std;


int main() {
  assert(get_debug_mode() == false);
  set_debug_mode(true);
  assert(get_debug_mode() == true);
  set_debug_mode(false);
  assert(get_debug_mode() == false);

  assert(eecs280_rand_int(1) == 0);
  assert(eecs280_rand_int(1) == 0);
  assert(eecs280_rand_int(1) == 0);

  assert(eecs280_rand_int(2) == 0);
  assert(eecs280_rand_int(2) == 0);
  assert(eecs280_rand_int(2) == 1);

  assert(eecs280_rand_int(3) == 2);
  assert(eecs280_rand_int(3) == 2);
  assert(eecs280_rand_int(3) == 0);

  assert(eecs280_rand_int(100) == 1);
  assert(eecs280_rand_int(100) == 17);
  assert(eecs280_rand_int(100) == 82);

  double epsilon = 0.001;
  assert((eecs280_rand_probability() - 0.278498) < epsilon);
  assert((eecs280_rand_probability() - 0.188382) < epsilon);
  assert((eecs280_rand_probability() - 0.546882) < epsilon);

  return 0;
}
