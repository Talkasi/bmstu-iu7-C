#include <stdio.h>
#include <stdint.h>

#define N_MAX 10

#define INPUT_LEN_ERROR 1
#define INPUT_ARRAY_ERROR 2

int arr_read(int arr[], size_t arr_len);
void arr_print(int arr[], size_t arr_len);

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

    if (arr_read(arr, arr_len))
    {
        printf("Input array error.\n");
        return INPUT_ARRAY_ERROR;
    }

    arr_len = arr_fibs_insertion(arr, arr_len);

    printf("New array:\n");
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
    int32_t fibs_arr[] = {0,        1,        1,        2,        3,         5,         8,         13,       21,
                          34,       55,       89,       144,      233,       377,       610,       987,      1597,
                          2584,     4181,     6765,     10946,    17711,     28657,     46368,     75025,    121393,
                          196418,   317811,   514229,   832040,   1346269,   2178309,   3524578,   5702887,  9227465,
                          14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437};

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

size_t arr_div_by_three_count(int arr[], size_t arr_len)
{
    size_t n_div_by_three = 0;

    for (size_t i = 0; i < arr_len; i++)
        if (arr[i] % 3 == 0)
            ++n_div_by_three;

    return n_div_by_three;
}
