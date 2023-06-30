#include "matrix.h"
#include <stdio.h>

int is_symmetric(int arr[], size_t arr_len);

int matrix_scan(arr_t matrix[], size_t n_rows, size_t n_cols)
{
    for (size_t i = 0; i < n_rows; ++i)
        for (size_t j = 0; j < n_cols; ++j)
            if (scanf("%d", &matrix[i][j]) != 1)
                return 1;

    return 0;
}

void symmetric_info_init(int symmetric_info[], arr_t matrix[], size_t n_rows, size_t n_cols)
{
    for (size_t i = 0; i < n_rows; ++i)
        symmetric_info[i] = is_symmetric(matrix[i], n_cols);
}

int is_symmetric(int arr[], size_t arr_len)
{
    size_t border = arr_len / 2;

    for (size_t i = 0; i < border; ++i)
        if (arr[i] != arr[arr_len - 1 - i])
            return 0;

    return 1;
}
