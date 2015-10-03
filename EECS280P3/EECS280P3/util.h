#ifndef UTIL_H
#define UTIL_H
/* Util.h
 *
 * Utility functions
 *
 * by Andrew DeOrio <awdeorio@umich.edu>
 * 2015-07-14
 */


//EFFECTS: sets debug mode to flag
//HINT: Use a static global variable in util.cpp to remember if debug mode is
//  enabled.  A static variable means that its scope is limited to one file.
//PROTIP: On the rare occasion that you're allowed to use a global variable,
// start it's name with the letter 'g' to make it obvious that it's global!
// e.g. g_my_global_variable or gMyGlobalVariable.
void set_debug_mode(bool flag);

//EFFECTS: returns true if debug mode is enabled, false otherwise
bool get_debug_mode();

//EFFECTS: returns a random integer in the range [0, x)
//  Prints "DEBUG eecs280_rand_probability() NUMBER\n" to stdout in debug mode
//REQUIRES: x > 0
//HINT: This function should use a single call to genrand_int31() from mt19937.h
//HINT: to get a smaller number from a big random integer, use the % operator
int eecs280_rand_int(int x);

//EFFECTS: returns a random double in the range [0,1]
//  Prints "DEBUG eecs280_rand_probability() NUMBER\n" to stdout in debug mode
//HINT: this function should use a single call to genrand_real1() from mt19937.h
double eecs280_rand_probability();

#endif
