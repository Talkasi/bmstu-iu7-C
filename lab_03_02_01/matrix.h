#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <stdlib.h>

#define N_COLUMNS_MAX 10
#define N_ROWS_MAX 10

#define N_INDEXES 2

typedef int arr_t[N_COLUMNS_MAX];

int matrix_scan(arr_t matrix[], size_t n_rows, size_t n_columns);
void matrix_print(arr_t matrix[], size_t n_rows, size_t n_columns);

int digits_sum(int num);
int min_digits_sum_index_find(arr_t matrix[], size_t n_rows, size_t n_columns, size_t *row_min, size_t *column_min);
void row_and_column_delete(arr_t matrix[], size_t *n_rows, size_t *n_columns, size_t row_del, size_t column_del);

#endif
