#include <stdio.h>

#define N_MAX 10
/* The maximum number of Fibonacci numbers that can be stored in int32_t */
#define FIB_MAX 43

#define INPUT_LEN_ERROR 1
#define INPUT_ARRAY_ERROR 2

int arr_read(int arr[], size_t arr_len);
void arr_print(int arr[], size_t arr_len);

void arr_fibs_compute(int fib_numbers[], size_t n_insert);
size_t arr_fibs_insertion(int arr[], size_t arr_len);
size_t arr_div_by_three_count(int arr[], size_t arr_len);

int main(void)
{
    int arr[N_MAX * 2];
    size_t arr_len;

    printf("Enter number of elements in the array: ");
    if (scanf("%zu", &arr_len) != 1 || arr_len == 0 || arr_len > N_MAX)
    {
        printf("Input length error.\n");
        return INPUT_LEN_ERROR;
    }

    printf("Enter elements of an array:\n");
    if (arr_read(arr, arr_len))
    {
        printf("Input array error.\n");
        return INPUT_ARRAY_ERROR;
    }

    arr_len = arr_fibs_insertion(arr, arr_len);

    printf("Elements of the new array:\n");
    arr_print(arr, arr_len);

    return 0;
}

int arr_read(int arr[], size_t arr_len)
{
    for (size_t i = 0; i < arr_len; ++i)
        if (scanf("%d", &arr[i]) != 1)
            return INPUT_ARRAY_ERROR;

    return 0;
}

void arr_print(int arr[], size_t arr_len)
{
    for (size_t i = 0; i < arr_len; ++i)
        printf("%d ", arr[i]);
}

size_t arr_fibs_insertion(int arr[], size_t arr_len)
{
    int fibs_arr[FIB_MAX];
    arr_fibs_compute(fibs_arr, FIB_MAX);

    size_t n_insert = arr_div_by_three_count(arr, arr_len);

    size_t step = n_insert;
    size_t end_flag = arr_len;

    for (size_t i = arr_len - 1; end_flag; --i)
    {
        end_flag = i;

        if (arr[i] % 3 == 0)
        {
            arr[i + step] = fibs_arr[step - 1];
            --step;
            arr[i + step] = arr[i];
        }
        else
            arr[i + step] = arr[i];
    }

    return arr_len + n_insert;
}

void arr_fibs_compute(int fib_numbers[], size_t n_insert)
{
    if (n_insert >= 1)
        fib_numbers[0] = 0;

    if (n_insert >= 2)
        fib_numbers[1] = 1;

    for (size_t i = 2; i < n_insert; ++i)
        fib_numbers[i] = fib_numbers[i - 1] + fib_numbers[i - 2];
}

size_t arr_div_by_three_count(int arr[], size_t arr_len)
{
    size_t n_div_by_three = 0;

    for (size_t i = 0; i < arr_len; i++)
        if (arr[i] % 3 == 0)
            ++n_div_by_three;

    return n_div_by_three;
}
