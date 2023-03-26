#include <stdio.h>

#define N_COLUMNS_MAX 10
#define N_ROWS_MAX 10

#define INPUT_N_ROWS_ERROR 1
#define INPUT_N_COLUMNS_ERROR 2
#define INPUT_MATRIX_ERROR 3

void arr_print(int arr[], size_t arr_len);
int matrix_read(int matrix[][N_COLUMNS_MAX], size_t n_rows, size_t n_columns);
int is_symmetric(int arr[], size_t arr_len);
void symmetric_info_init(int symmetric_info[], int matrix[][N_COLUMNS_MAX], size_t n_rows, size_t n_columns);

int main(void)
{
    int matrix[N_ROWS_MAX][N_COLUMNS_MAX];
    size_t n_rows;
    size_t n_columns;

    printf("Input number of rows: ");
    if (scanf("%zu", &n_rows) != 1 || n_rows == 0 || n_rows > N_ROWS_MAX)
    {
        printf("Input rows number error.\n");
        return INPUT_N_ROWS_ERROR;
    }

    printf("Input number of columns: ");
    if (scanf("%zu", &n_columns) != 1 || n_columns == 0 || n_columns > N_COLUMNS_MAX)
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

    int symmetric_info[N_ROWS_MAX];

    symmetric_info_init(symmetric_info, matrix, n_rows, n_columns);

    printf("Elements of the new matrix:\n");
    arr_print(symmetric_info, n_rows);

    return 0;
}

int matrix_read(int matrix[][N_COLUMNS_MAX], size_t n_rows, size_t n_columns)
{
    for (size_t i = 0; i < n_rows; ++i)
        for (size_t j = 0; j < n_columns; ++j)
            if (scanf("%d", &matrix[i][j]) != 1)
                return 1;

    return 0;
}

void symmetric_info_init(int symmetric_info[], int matrix[][N_COLUMNS_MAX], size_t n_rows, size_t n_columns)
{
    for (size_t i = 0; i < n_rows; ++i)
        symmetric_info[i] = is_symmetric(matrix[i], n_columns);
}

int is_symmetric(int arr[], size_t arr_len)
{
    size_t border = arr_len / 2;

    for (size_t i = 0; i < border; ++i)
        if (arr[i] != arr[arr_len - 1 - i])
            return 0;

    return 1;
}

void arr_print(int arr[], size_t arr_len)
{
    for (size_t i = 0; i < arr_len; ++i)
        printf("%d ", arr[i]);
}
