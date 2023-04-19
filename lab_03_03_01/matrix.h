#ifndef MATRIX_H
#define MATRIX_H
#include <stdlib.h>

#define N_COLUMNS_MAX 10

typedef int arr_t[N_COLUMNS_MAX];

int matrix_scan(arr_t matrix[], size_t n_rows, size_t n_cols);
void matrix_print(arr_t matrix[], size_t n_rows, size_t n_cols);

void rows_swap(arr_t matrix[], size_t n_cols, size_t row1, size_t row2);
void bubble_sort(arr_t matrix[], size_t n_rows, size_t n_cols);

#endif
