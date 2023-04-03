#include "matrix.h"
#include <stdio.h>

#define INPUT_N_ROWS_ERROR 1
#define INPUT_N_COLUMNS_ERROR 2
#define NOT_SQUARE_MATRIX_ERROR 3

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

    if (n_columns != n_rows)
    {
        printf("Not square matrix error.\n");
        return NOT_SQUARE_MATRIX_ERROR;
    }

    spiral_init(matrix, n_rows, n_columns);

    printf("Modified matrix is:\n");
    matrix_print(matrix, n_rows, n_columns);

    return 0;
}
