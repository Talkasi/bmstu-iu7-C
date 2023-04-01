#include <stdlib.h>

#ifndef __MATRIX_H__
#define __MATRIX_H__

#define N_COLUMNS_MAX 10
#define N_ROWS_MAX 10

typedef int matrix_t[N_ROWS_MAX];

int matrix_read(matrix_t matrix[N_COLUMNS_MAX], size_t n_rows, size_t n_columns);
void matrix_print(matrix_t matrix[N_COLUMNS_MAX], size_t n_rows, size_t n_columns);

size_t max_index(int arr[], size_t arr_len);
void max_indexes_arr(size_t max_indexes[], matrix_t matrix[N_COLUMNS_MAX], size_t n_rows, size_t n_columns);

void arr_copy(int dst[], int src[], size_t src_len);
void insertion_sort(matrix_t matrix[N_COLUMNS_MAX], size_t n_rows, size_t n_columns, size_t max_indexes[N_COLUMNS_MAX]);

#endif
