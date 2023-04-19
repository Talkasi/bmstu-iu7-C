#ifndef MATRIX_H
#define MATRIX_H
#include <stdlib.h>

#define N_COLUMNS_MAX 10

typedef int arr_t[N_COLUMNS_MAX];

int matrix_scan(arr_t matrix[], size_t n_rows, size_t n_cols);
void symmetric_info_init(int symmetric_info[], arr_t matrix[], size_t n_rows, size_t n_cols);

#endif
