#include "matrix.h"
#include <stdio.h>

int matrix_scan(arr_t matrix[], size_t n_rows, size_t n_columns)
{
    for (size_t i = 0; i < n_rows; ++i)
        for (size_t j = 0; j < n_columns; ++j)
            if (scanf("%d", &matrix[i][j]) != 1)
                return 1;

    return 0;
}

void matrix_print(arr_t matrix[], size_t n_rows, size_t n_columns)
{
    for (size_t i = 0; i < n_rows; ++i)
    {
        for (size_t j = 0; j < n_columns; ++j)
            printf("%8d ", matrix[i][j]);

        printf("\n");
    }
}

void rows_special_swap(arr_t matrix[], size_t n_rows, size_t n_columns)
{
    size_t k = 0;

    for (size_t i = 0; i < n_rows / 2; ++i)
    {
        for (size_t j = k; j < n_columns - k; ++j)
            swap(&matrix[i][j], &matrix[n_rows - i - 1][j]);

        ++k;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
