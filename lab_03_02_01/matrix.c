#include "matrix.h"
#include <stdio.h>

int digits_sum(int num);

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
            printf("%8.d ", matrix[i][j]);

        printf("\n");
    }
}

int min_digits_sum_index_find(arr_t matrix[], size_t n_rows, size_t n_cols, size_t *row_min, size_t *col_min)
{
    int min_digits_sum = matrix[0][0];
    *row_min = 0;
    *col_min = 0;

    for (size_t i = 0; i < n_rows; ++i)
        for (size_t j = 0; j < n_cols; ++j)
        {
            int sum_cur = digits_sum(matrix[i][j]);
            if (sum_cur < min_digits_sum)
            {
                min_digits_sum = sum_cur;
                *row_min = i;
                *col_min = j;
            }
        }

    return min_digits_sum;
}

int digits_sum(int num)
{
    int sum = 0;
    num = abs(num);

    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

void row_and_column_delete(arr_t matrix[], size_t *n_rows, size_t *n_cols, size_t row_del, size_t col_del)
{
    for (size_t i = row_del; i < *n_rows - 1; ++i)
        for (size_t j = 0; j < *n_cols; ++j)
            matrix[i][j] = matrix[i + 1][j];

    --*n_rows;

    for (size_t j = col_del; j < *n_cols - 1; ++j)
        for (size_t i = 0; i < *n_rows; ++i)
            matrix[i][j] = matrix[i][j + 1];

    --*n_cols;
}
