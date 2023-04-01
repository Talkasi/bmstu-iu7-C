#include "matrix.h"
#include <stdio.h>

#define INPUT_N_ERROR 1
#define INPUT_MATRIX_ERROR 2

int main(void)
{
    arr_t matrix[N_COLUMNS_MAX];
    size_t n;

    printf("Input number of rows, columns: ");
    if (scanf("%zu", &n) != 1 || n < 1 || n > N_ROWS_MAX)
    {
        printf("Input rows, columns number error.\n");
        return INPUT_N_ERROR;
    }

    printf("Enter elements of matrix line by line:\n");
    if (matrix_read(matrix, n, n))
    {
        printf("Input matrix error.\n");
        return INPUT_MATRIX_ERROR;
    }

    rows_special_swap(matrix, n, n);

    printf("New matrix is:\n");
    matrix_print(matrix, n, n);

    return 0;
}
