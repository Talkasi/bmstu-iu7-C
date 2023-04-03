#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <stdlib.h>

#define N_COLUMNS_MAX 10
#define N_ROWS_MAX 10

typedef int arr_t[N_COLUMNS_MAX];

int matrix_scan(arr_t matrix[], size_t n_rows, size_t n_columns);
void matrix_print(arr_t matrix[], size_t n_rows, size_t n_columns);

int max(int arr[N_COLUMNS_MAX], size_t arr_len);
void rows_swap(arr_t matrix[], size_t n_columns, size_t row1, size_t row2);
void bubble_sort(arr_t matrix[], size_t n_rows, size_t n_columns);

#endif
