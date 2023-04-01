#include "matrix.h"
#include <stdio.h>

#define INPUT_N_ROWS_ERROR 1
#define INPUT_N_COLUMNS_ERROR 2
#define INPUT_MATRIX_ERROR 3

int main(void)
{
    arr_t matrix[N_COLUMNS_MAX];
    size_t n_rows;
    size_t n_columns;

    printf("Input number of rows: ");
    if (scanf("%zu", &n_rows) != 1 || n_rows < 2 || n_rows > N_ROWS_MAX)
    {
        printf("Input rows number error.\n");
        return INPUT_N_ROWS_ERROR;
    }

    printf("Input number of columns: ");
    if (scanf("%zu", &n_columns) != 1 || n_columns < 2 || n_columns > N_COLUMNS_MAX)
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

    size_t indexes[N_INDEXES];

    min_digits_sum_indexes(indexes, matrix, n_rows, n_columns);
    row_column_delete(matrix, &n_rows, &n_columns, indexes);

    printf("New matrix is:\n");
    matrix_print(matrix, n_rows, n_columns);

    return 0;
}
