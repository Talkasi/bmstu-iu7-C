#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <stdlib.h>

#define N_COLUMNS_MAX 10
#define N_ROWS_MAX 10

typedef int arr_t[N_ROWS_MAX];

int matrix_read(arr_t matrix[N_COLUMNS_MAX], size_t n_rows, size_t n_columns);
void matrix_print(arr_t matrix[N_COLUMNS_MAX], size_t n_rows, size_t n_columns);

int digits_sum(int num);
size_t arr_by_digits_sum_init(int arr[], arr_t matrix[N_COLUMNS_MAX], size_t n_rows, size_t n_columns, int border);

void cyclic_left_shift(int arr[], size_t arr_len, size_t n_shift);
void matrix_by_digits_sum_init(arr_t matrix[N_COLUMNS_MAX], size_t n_rows, size_t n_columns, int arr[], int border);

#endif
