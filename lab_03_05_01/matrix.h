#ifndef MATRIX_H
#define MATRIX_H
#include <stdlib.h>

#define N_COLUMNS_MAX 10

typedef int arr_t[N_COLUMNS_MAX];

int matrix_scan(arr_t matrix[], size_t n_rows, size_t n_cols);
void matrix_print(arr_t matrix[], size_t n_rows, size_t n_cols);

void cyclic_left_shift(int arr[], size_t arr_len, size_t n_shift);
void matrix_by_digits_sum_change(arr_t matrix[], size_t n_rows, size_t n_cols, int arr[], int min_digits_sum);
size_t arr_by_digits_sum_fill(int arr[], arr_t matrix[], size_t n_rows, size_t n_cols, int min_digits_sum);

#endif
