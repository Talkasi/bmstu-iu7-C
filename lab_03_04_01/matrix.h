#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <stdlib.h>

#define N_COLUMNS_MAX 10
#define N_ROWS_MAX 10

typedef int arr_t[N_COLUMNS_MAX];

int matrix_scan(arr_t matrix[], size_t n_rows, size_t n_columns);
void matrix_print(arr_t matrix[], size_t n_rows, size_t n_columns);

void swap(int *a, int *b);
void rows_special_swap(arr_t matrix[], size_t n_rows, size_t n_columns);

#endif
