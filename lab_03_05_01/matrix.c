#include "matrix.h"
#include <stdio.h>

int matrix_read(arr_t matrix[N_COLUMNS_MAX], size_t n_rows, size_t n_columns)
{
    for (size_t i = 0; i < n_rows; ++i)
        for (size_t j = 0; j < n_columns; ++j)
            if (scanf("%d", &matrix[i][j]) != 1)
                return 1;

    return 0;
}

void matrix_print(arr_t matrix[N_COLUMNS_MAX], size_t n_rows, size_t n_columns)
{
    for (size_t i = 0; i < n_rows; ++i)
    {
        for (size_t j = 0; j < n_columns; ++j)
            printf("%8d ", matrix[i][j]);

        printf("\n");
    }
}

size_t arr_by_digits_sum_init(int arr[], arr_t matrix[N_COLUMNS_MAX], size_t n_rows, size_t n_columns, int border)
{
    size_t arr_len = 0;

    for (size_t i = 0; i < n_rows; ++i)
        for (size_t j = 0; j < n_columns; ++j)
            if (digits_sum(matrix[i][j]) > border)
                arr[arr_len++] = matrix[i][j];

    return arr_len;
}

void cyclic_left_shift(int arr[], size_t arr_len, size_t n_shift)
{
    int temp[N_ROWS_MAX * N_COLUMNS_MAX];
    int i_temp = 0;

    for (size_t i = 0; i < n_shift; ++i)
        temp[i] = arr[i];

    for (size_t i = n_shift; i < arr_len; ++i)
        arr[i - n_shift] = arr[i];

    for (size_t i = arr_len - n_shift; i < arr_len; ++i)
        arr[i] = temp[i_temp++];
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

void matrix_by_digits_sum_init(arr_t matrix[N_COLUMNS_MAX], size_t n_rows, size_t n_columns, int arr[], int border)
{
    size_t i_arr = 0;

    for (size_t i = 0; i < n_rows; ++i)
        for (size_t j = 0; j < n_columns; ++j)
            if (digits_sum(matrix[i][j]) > border)
                matrix[i][j] = arr[i_arr++];
}
