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

size_t max_index_init(int arr[], size_t arr_len)
{
    size_t max_i = 0;
    int max = arr[max_i];

    for (size_t i = 0; i < arr_len; ++i)
        if (arr[i] > max)
        {
            max = arr[i];
            max_i = i;
        }

    return max_i;
}

void max_indexes_arr(size_t max_indexes[], arr_t matrix[N_COLUMNS_MAX], size_t n_rows, size_t n_columns)
{
    for (size_t i = 0; i < n_rows; ++i)
        max_indexes[i] = max_index_init(matrix[i], n_columns);
}

void insertion_sort(arr_t matrix[N_COLUMNS_MAX], size_t n_rows, size_t n_columns, size_t indexes[N_COLUMNS_MAX])
{
    for (size_t i = 0; i < n_rows - 1; ++i)
    {
        int zero_flag = 0;
        int temp[N_COLUMNS_MAX];

        size_t temp_max_i = indexes[i + 1];
        arr_copy(temp, matrix[i + 1], n_columns);
        int temp_max = temp[temp_max_i];

        size_t j = i;

        while (matrix[j][indexes[j]] < temp_max)
        {
            indexes[j + 1] = indexes[j];
            arr_copy(matrix[j + 1], matrix[j], n_columns);

            if (j == 0)
            {
                zero_flag = 1;
                break;
            }
            else
                --j;
        }

        indexes[j + 1 - zero_flag] = temp_max_i;
        arr_copy(matrix[j + 1 - zero_flag], temp, n_columns);
    }
}

void arr_copy(int dst[], int src[], size_t src_len)
{
    for (size_t i = 0; i < src_len; ++i)
        dst[i] = src[i];
}
