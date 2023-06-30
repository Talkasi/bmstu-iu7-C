#include "matrix.h"
#include <stdio.h>

int max(int arr[], size_t arr_len);

int matrix_scan(arr_t matrix[], size_t n_rows, size_t n_cols)
{
    for (size_t i = 0; i < n_rows; ++i)
        for (size_t j = 0; j < n_cols; ++j)
            if (scanf("%d", &matrix[i][j]) != 1)
                return 1;

    return 0;
}

void matrix_print(arr_t matrix[], size_t n_rows, size_t n_cols)
{
    for (size_t i = 0; i < n_rows; ++i)
    {
        for (size_t j = 0; j < n_cols; ++j)
            printf("%8d ", matrix[i][j]);

        printf("\n");
    }
}

void bubble_sort(arr_t matrix[], size_t n_rows, size_t n_cols)
{
    int max_row_cur, max_row_next;
    for (size_t i = 0; i < n_rows; ++i)
        for (size_t j = 0; j < n_rows - 1 - i; ++j)
        {
            max_row_cur = max(matrix[j], n_cols);
            max_row_next = max(matrix[j + 1], n_cols);
            if (max_row_cur < max_row_next)
                rows_swap(matrix, n_cols, j, j + 1);
        }
}

int max(int arr[], size_t arr_len)
{
    int max = arr[0];

    for (size_t i = 1; i < arr_len; ++i)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

void rows_swap(arr_t matrix[], size_t n_cols, size_t row1, size_t row2)
{
    for (size_t i = 0; i < n_cols; ++i)
    {
        int temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}
