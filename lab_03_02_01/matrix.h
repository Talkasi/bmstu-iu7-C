#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <stdlib.h>

#define N_COLUMNS_MAX 10
#define N_ROWS_MAX 10

#define N_INDEXES 2

#define MAX(a, b) (a) > (b) ? (a) : (b)
typedef int arr_t[N_ROWS_MAX];

int matrix_read(arr_t matrix[N_COLUMNS_MAX], size_t n_rows, size_t n_columns);
void matrix_print(arr_t matrix[N_COLUMNS_MAX], size_t n_rows, size_t n_columns);

void matrix_transpose(arr_t matrix[N_COLUMNS_MAX], size_t *n_rows, size_t *n_columns);

int digits_sum(int num);
void min_digits_sum_indexes(size_t indexes[N_INDEXES], arr_t matrix[N_COLUMNS_MAX], size_t n_rows, size_t n_columns);

void elem_delete(int arr[], size_t arr_len, size_t position_to_delete);
void row_column_delete(arr_t matrix[N_COLUMNS_MAX], size_t *n_rows, size_t *n_columns, size_t indexes[N_INDEXES]);

#endif
