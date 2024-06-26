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
            printf("%8d ", matrix[i][j]);

        printf("\n");
    }
}

size_t arr_by_digits_sum_fill(int arr[], arr_t matrix[], size_t n_rows, size_t n_cols, int min_digits_sum)
{
    size_t arr_len = 0;

    for (size_t i = 0; i < n_rows; ++i)
        for (size_t j = 0; j < n_cols; ++j)
            if (digits_sum(matrix[i][j]) > min_digits_sum)
                arr[arr_len++] = matrix[i][j];

    return arr_len;
}

void cyclic_left_shift(int arr[], size_t arr_len, size_t n_shift)
{
    for (size_t k = 0; k < n_shift; ++k)
    {
        int temp = arr[0];

        for (size_t i = 1; i < arr_len; ++i)
            arr[i - 1] = arr[i];

        arr[arr_len - 1] = temp;
    }
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

void matrix_by_digits_sum_change(arr_t matrix[], size_t n_rows, size_t n_cols, int arr[], int min_digits_sum)
{
    size_t i_arr = 0;

    for (size_t i = 0; i < n_rows; ++i)
        for (size_t j = 0; j < n_cols; ++j)
            if (digits_sum(matrix[i][j]) > min_digits_sum)
                matrix[i][j] = arr[i_arr++];
}
