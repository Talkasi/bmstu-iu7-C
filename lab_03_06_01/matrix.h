#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <stdlib.h>

#define N_COLUMNS_MAX 10
#define N_ROWS_MAX 10

typedef int arr_t[N_COLUMNS_MAX];

void matrix_print(arr_t matrix[], size_t n_rows, size_t n_columns);
void spiral_init(arr_t matrix[], size_t n_rows, size_t n_columns);

#endif
