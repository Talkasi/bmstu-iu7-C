#include "matrix.h"
#include <stdio.h>

#define INPUT_N_ROWS_ERROR 1
#define INPUT_N_COLUMNS_ERROR 2
#define INPUT_MATRIX_ERROR 3

int main(void)
{
    matrix_t matrix[N_COLUMNS_MAX];
    size_t n_rows;
    size_t n_columns;

    printf("Input number of rows: ");
    if (scanf("%zu", &n_rows) != 1 || n_rows < 1 || n_rows > N_ROWS_MAX)
    {
        printf("Input rows number error.\n");
        return INPUT_N_ROWS_ERROR;
    }

    printf("Input number of columns: ");
    if (scanf("%zu", &n_columns) != 1 || n_columns < 1 || n_columns > N_COLUMNS_MAX)
    {
        printf("Input columns number error.\n");
        return INPUT_N_COLUMNS_ERROR;
    }

    printf("Enter elements of matrix line by line:\n");
    if (matrix_read(matrix, n_rows, n_columns))
    {
        printf("Input matrix error.\n");
        return INPUT_MATRIX_ERROR;
    }

    size_t max_indexes[N_COLUMNS_MAX];

    max_indexes_arr(max_indexes, matrix, n_rows, n_columns);
    insertion_sort(matrix, n_rows, n_columns, max_indexes);

    printf("Sorted matrix is:\n");
    matrix_print(matrix, n_rows, n_columns);

    return 0;
}
