#include "matrix.h"
#include <stdio.h>

int matrix_read(matrix_t matrix[N_COLUMNS_MAX], size_t n_rows, size_t n_columns)
{
    for (size_t i = 0; i < n_rows; ++i)
        for (size_t j = 0; j < n_columns; ++j)
            if (scanf("%d", &matrix[i][j]) != 1)
                return 1;

    return 0;
}

void matrix_print(matrix_t matrix[N_COLUMNS_MAX], size_t n_rows, size_t n_columns)
{
    for (size_t i = 0; i < n_rows; ++i)
    {
        for (size_t j = 0; j < n_columns; ++j)
            printf("%8.d ", matrix[i][j]);

        printf("\n");
    }
}

void indexes_of_digits_min_elem(size_t *min_el_row, size_t *min_el_column, matrix_t matrix[N_COLUMNS_MAX],
                                size_t n_rows, size_t n_columns)
{
    int min_digits_sum = digits_sum(abs(matrix[0][0]));
    *min_el_row = 0;
    *min_el_column = 0;

    for (size_t i = 0; i < n_rows; ++i)
        for (size_t j = 0; j < n_columns; ++j)
        {
            int digits_sum_cur = digits_sum(abs(matrix[i][j]));
            if (digits_sum_cur < min_digits_sum)
            {
                min_digits_sum = digits_sum_cur;
                *min_el_row = i;
                *min_el_column = j;
            }
        }
}

int digits_sum(int num)
{
    int sum = 0;

    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

void row_and_column_delete(matrix_t matrix[N_COLUMNS_MAX], size_t *n_rows, size_t *n_columns, size_t min_el_row,
                           size_t min_el_column)
{
    for (size_t i = 0; i < *n_rows; ++i)
        elem_delete(matrix[i], *n_columns, min_el_column);

    --*n_columns;
    matrix_transpose(matrix, n_rows, n_columns);

    for (size_t i = 0; i < *n_rows; ++i)
        elem_delete(matrix[i], *n_columns, min_el_row);

    --*n_columns;
    matrix_transpose(matrix, n_rows, n_columns);
}

void elem_delete(int arr[], size_t arr_len, size_t position_to_delete)
{
    for (size_t i = position_to_delete; i < arr_len - 1; ++i)
        arr[i] = arr[i + 1];
}

void matrix_transpose(matrix_t matrix[N_COLUMNS_MAX], size_t *n_rows, size_t *n_columns)
{
    size_t n_sq = MAX(*n_rows, *n_columns);

    for (size_t i = 0; i < n_sq; ++i)
        for (size_t j = i; j < n_sq; ++j)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }

    int temp = *n_columns;
    *n_columns = *n_rows;
    *n_rows = temp;
}
