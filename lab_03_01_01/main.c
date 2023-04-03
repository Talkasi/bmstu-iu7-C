#include "matrix.h"
#include <stdio.h>

#define INPUT_N_ROWS_ERROR 1
#define INPUT_N_COLUMNS_ERROR 2
#define INPUT_MATRIX_ERROR 3

void arr_print(int arr[], size_t arr_len);

int main(void)
{
    arr_t matrix[N_COLUMNS_MAX];
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

    printf("Enter elements of matrix line by line:\n");
    if (matrix_scan(matrix, n_rows, n_columns))
    {
        printf("Input matrix error.\n");
        return INPUT_MATRIX_ERROR;
    }

    int symmetric_info[N_ROWS_MAX];

    symmetric_info_init(symmetric_info, matrix, n_rows, n_columns);

    printf("Elements of the symmetric info array:\n");
    arr_print(symmetric_info, n_rows);

    return 0;
}

void arr_print(int arr[], size_t arr_len)
{
    for (size_t i = 0; i < arr_len; ++i)
        printf("%d ", arr[i]);
}
