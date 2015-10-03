#ifndef MATRIX_H
#define MATRIX_H
/* Matrix.h
 *
 * A 2D matrix library
 *
 * by Andrew DeOrio <awdeorio@umich.edu>
 * 2015-07-14
 */

////////////////////////////////////////////////////////////////////////////////
// Matrix

const int MAX_NUM_ROWS = 100;
const int MAX_NUM_COLUMNS = 100;

struct Matrix {
  //A 2D matrix, stored in a 1D array

  int num_rows;
  int num_columns;
  char array[MAX_NUM_ROWS * MAX_NUM_COLUMNS];

};

//EFFECTS: Initializes the number of rows and columns of a matrix
//REQUIRES: num_rows_in < MAX_NUM_ROWS and num_rows_in > 0
//          num_columns_in < MAX_NUM_COLUMNS and num_columns_in > 0
//          ptr points to a non-NULL Matrix
//  You must check the REQUIRES clause using assert
void Matrix_init(Matrix *ptr, int num_rows_in, int num_columns_in);

//EFFECTS: returns the total number of items in the Matrix
//REQUIRES: ptr points to a non-NULL Matrix
//  You must check the REQUIRES clause using assert
int Matrix_size(const Matrix *ptr);

//EFFECTS: returns the number of rows in the Matrix
//REQUIRES: ptr points to a non-NULL Matrix
//  You must check the REQUIRES clause using assert
int Matrix_num_rows(const Matrix *ptr);

//EFFECTS: returns the number of columns in the Matrix
//REQUIRES: ptr points to a non-NULL Matrix
//  You must check the REQUIRES clause using assert
int Matrix_num_columns(const Matrix *ptr);

//EFFECTS: returns the row number of the location pointed to by location_ptr
//REQUIRES: ptr points to a non-NULL Matrix
//          The address of location_ptr is within the Matrix
//  You must check the REQUIRES clause using assert
int Matrix_row(const Matrix *ptr, const char *location_ptr);

//EFFECTS: returns the column number of the location pointed to by location_ptr
//REQUIRES: ptr points to a non-NULL Matrix
//          The address of location_ptr is within the Matrix
//  You must check the REQUIRES clause using assert
int Matrix_col(const Matrix *ptr, const char *location_ptr);

//EFFECTS: returns a pointer to item at location (row,col)
//REQUIRES: row >= 0 and row < matrix number of rows
//          col >= 0  and col < matrix number of columns
//          ptr points to a non-NULL Matrix
//  You must check the REQUIRES clause using assert
char * Matrix_at(Matrix *ptr, int row, int col);

//EFFECTS: returns a pointer to item at location (row,col)
//  Uses assert() to ensure row and col are in range
//  Note that this is a const-version of the above function.  It's needed
//  for when Matrix_at() is called with a "const Matrix*" object.  Duplicate
//  the code from Matrix_at() here.
//REQUIRES: row >= 0 and row < matrix number of rows
//          col >= 0  and col < matrix number of columns
//          ptr points to a non-NULL Matrix
//  You must check the REQUIRES clause using assert
const char * Matrix_at(const Matrix *ptr, int row, int col);

//EFFECTS: prints Matrix to stdout, with a space after each item, for example:
/*
X O O X X
X   O O X
X     O X
X X X X
O   O X O
*/
//REQUIRES: ptr points to a non-NULL Matrix
//  You must check the REQUIRES clause using assert
void Matrix_print(const Matrix *ptr);

//EFFECTS: returns a range of items within a rectangular radius of
//  (m_center, n_center).  It does not "go off the edge" of the Matrix, but
//  rather truncates the range.  Includes the center point.  Items are returned
//  in dest in order from left-to-right, top-to-bottom.  dest_size is set
//  to the size of dest.  For example:
/*
src =
X O O X X
X   O O X
X     O X
X X X X
O   O X O
(m_center, n_center) = (1, 3)
radius = 1
dest = "OXXOOX OX"
dest_size = 9
*/
//REQUIRES: dest big enough to hold all items in range
//  You must check the REQUIRES clause using assert
void Matrix_range_radius(const Matrix *src, int row_center, int col_center,
                         int radius, char *dest, int *dest_size);

//EFFECTS: returns the first cell matching c, starting from (0,0).  Searches
//  left-to-right, top-to-bottom (AKA row-major). Returns NULL if not found.
//REQUIRES: ptr points to a non-NULL Matrix
//  You must check the REQUIRES clause using assert
char * Matrix_search_simple(Matrix *ptr, char c);

//EFFECTS: returns a random cell matching c
//  To ensure that random number generation is consistent with solution, call
//  eecs280_rand_int() exactly twice: first for "row", second for "col".  Do not
//  generate any more random numbers than needed to complete search.
//REQUIRES: a solution exists, ptr points to a non-NULL Matrix
//  You must check the REQUIRES clause using assert
char * Matrix_search_random(Matrix *ptr, char c);


#endif
