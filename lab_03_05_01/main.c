#include "matrix.h"
#include <stdio.h>

#define N_ROWS_MAX 10

#define INPUT_N_ROWS_ERROR 1
#define INPUT_N_COLUMNS_ERROR 2
#define INPUT_MATRIX_ERROR 3
#define NO_ELEMENTS_ERROR 4

#define MIN_DIGITS_SUM 10
#define N_SHIFT 3

int main(void)
{
    arr_t matrix[N_ROWS_MAX];
    size_t n_rows;
    size_t n_cols;

    printf("Enter number of rows: ");
    if (scanf("%zu", &n_rows) != 1 || n_rows == 0 || n_rows > N_ROWS_MAX)
    {
        printf("Input rows number error.\n");
        return INPUT_N_ROWS_ERROR;
    }

    printf("Enter number of columns: ");
    if (scanf("%zu", &n_cols) != 1 || n_cols == 0 || n_cols > N_COLUMNS_MAX)
    {
        printf("Input columns number error.\n");
        return INPUT_N_COLUMNS_ERROR;
    }

    printf("Enter elements of matrix line by line:\n");
    if (matrix_scan(matrix, n_rows, n_cols))
    {
        printf("Input matrix error.\n");
        return INPUT_MATRIX_ERROR;
    }

    int arr[N_COLUMNS_MAX * N_ROWS_MAX];
    size_t arr_len = arr_by_digits_sum_fill(arr, matrix, n_rows, n_cols, MIN_DIGITS_SUM);

    if (arr_len == 0)
    {
        printf("No appropriate elements error.\n");
        return NO_ELEMENTS_ERROR;
    }

    cyclic_left_shift(arr, arr_len, N_SHIFT);

    matrix_by_digits_sum_change(matrix, n_rows, n_cols, arr, MIN_DIGITS_SUM);

    printf("Modified matrix is:\n");
    matrix_print(matrix, n_rows, n_cols);

    return 0;
}
