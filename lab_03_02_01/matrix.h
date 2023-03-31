#include <stdlib.h>

#ifndef __MATRIX_H__
#define __MATRIX_H__

#define N_COLUMNS_MAX 10
#define N_ROWS_MAX 10

#define MAX(a, b) (a) > (b) ? (a) : (b)
typedef int matrix_t[N_ROWS_MAX];

int digits_sum(int num);
int matrix_read(matrix_t matrix[N_COLUMNS_MAX], size_t n_rows, size_t n_columns);
void matrix_print(matrix_t matrix[N_COLUMNS_MAX], size_t n_rows, size_t n_columns);
void matrix_transpose(matrix_t matrix[N_COLUMNS_MAX], size_t *n_rows, size_t *n_columns);
void elem_delete(int arr[], size_t arr_len, size_t position_to_delete);
void indexes_of_digits_min_elem(size_t *min_el_row, size_t *min_el_column, matrix_t matrix[N_COLUMNS_MAX],
                                size_t n_rows, size_t n_columns);
void row_and_column_delete(matrix_t matrix[N_COLUMNS_MAX], size_t *n_rows, size_t *n_columns, size_t min_el_row,
                           size_t min_el_column);
#endif
