#include <stdio.h>

#define NMAX 10

int read_array(int *arr, int arr_len);
void print_array(int *arr, int arr_len);
int fib_insertion(int *arr, int arr_len);
void get_fib_pair(int *fib_cur, int *fib_next, int number);

int main(void)
{
    int arr[NMAX * 2];
    int arr_len;

    printf("Enter number of elements in the array: ");
    if (scanf("%d", &arr_len) != 1 || arr_len <= 0 || arr_len > NMAX)
    {
        printf("Input error.");
        return 1;
    }

    if (read_array(arr, arr_len))
    {
        printf("Input error.");
        return 1;
    }

    arr_len = fib_insertion(arr, arr_len);

    print_array(arr, arr_len);

    return 0;
}

int read_array(int *arr, int arr_len)
{
    for (int i = 0; i < arr_len; ++i)
    {
        printf("Enter element of an array: ");
        if (scanf("%d", &arr[i]) != 1)
            return 1;
    }

    return 0;
}

void print_array(int *arr, int arr_len)
{
    printf("Elements of the array:");
    for (int i = 0; i < arr_len; ++i)
        printf(" %d", arr[i]);
}

int fib_insertion(int *arr, int arr_len)
{
    int fib_cur = 0, fib_next = 1;
    int n_insert = 0;

    for (int i = 0; i < arr_len; i++)
        if (arr[i] % 3 == 0)
            ++n_insert;

    get_fib_pair(&fib_cur, &fib_next, n_insert - 1);
    int step = n_insert;

    for (int i = arr_len - 1; i >= 0; i--)
    {
        if (arr[i] % 3 == 0)
        {
            arr[i + step] = fib_cur;
            /* Getting previous pair of the fibonacci numbers */
            fib_cur = fib_next - fib_cur;
            fib_next = arr[i + step];

            --step;
            arr[i + step] = arr[i];
        }
        else
            arr[i + step] = arr[i];
    }

    return arr_len + n_insert;
}

void get_fib_pair(int *fib_cur, int *fib_next, int number)
{
    int temp;

    for (int i = 0; i < number; ++i)
    {
        temp = *fib_cur;
        *fib_cur = *fib_next;
        *fib_next += temp;
    }
}
