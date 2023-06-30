#include "matrix.h"
#include <stdio.h>

void matrix_print(arr_t matrix[], size_t n_rows, size_t n_cols)
{
    for (size_t i = 0; i < n_rows; ++i)
    {
        for (size_t j = 0; j < n_cols; ++j)
            printf("%8d ", matrix[i][j]);

        printf("\n");
    }
}

void spiral_fill(arr_t matrix[], size_t n_rows, size_t n_cols)
{
    size_t i_start = 0, i_end = 0;
    size_t j_start = 0, j_end = 0;
    size_t i = 0;
    size_t j = 0;
    int number = 1;

    while (number <= (int)(n_rows * n_cols))
    {
        matrix[i][j] = number++;

        if (i == i_start && j < n_cols - j_end - 1)
            ++j;
        else if (j == n_cols - j_end - 1 && i < n_rows - i_end - 1)
            ++i;
        else if (i == n_rows - i_end - 1 && j > j_end)
            --j;
        else
            --i;

        if ((i == i_start + 1) && (j == j_start) && (j_start != n_cols - j_end - 1))
        {
            ++i_start;
            ++i_end;
            ++j_start;
            ++j_end;
        }
    }
}
