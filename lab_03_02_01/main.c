#include "matrix.h"
#include <stdio.h>

#define INPUT_N_ROWS_ERROR 1
#define INPUT_N_COLUMNS_ERROR 2
#define INPUT_MATRIX_ERROR 3
#define EMPTY_MATRIX_ERROR 4

int main(void)
{
    arr_t matrix[N_ROWS_MAX];
    size_t n_rows;
    size_t n_columns;

    printf("Enter number of rows: ");
    if (scanf("%zu", &n_rows) != 1 || n_rows == 0 || n_rows > N_ROWS_MAX)
    {
        printf("Input rows number error.\n");
        return INPUT_N_ROWS_ERROR;
    }

    printf("Enter number of columns: ");
    if (scanf("%zu", &n_columns) != 1 || n_columns == 0 || n_columns > N_COLUMNS_MAX)
    {
        printf("Input columns number error.\n");
        return INPUT_N_COLUMNS_ERROR;
    }

    if (n_rows == 1 || n_columns == 1)
    {
        printf("Matrix after modifies will be empty.\n");
        return EMPTY_MATRIX_ERROR;
    }

    printf("Enter elements of matrix line by line:\n");
    if (matrix_scan(matrix, n_rows, n_columns))
    {
        printf("Input matrix error.\n");
        return INPUT_MATRIX_ERROR;
    }

    size_t row_del, column_del;

    min_digits_sum_index_find(matrix, n_rows, n_columns, &row_del, &column_del);
    row_and_column_delete(matrix, &n_rows, &n_columns, row_del, column_del);

    printf("Modified matrix is:\n");
    matrix_print(matrix, n_rows, n_columns);

    return 0;
}
