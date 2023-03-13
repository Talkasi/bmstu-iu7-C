#include <math.h>
#include <stdio.h>

#define NMAX 10

int is_prime(int number);
int read_array(int *arr, int arr_len);
int prime_copy(int *dst, int *src, int src_len);

int main(void)
{
    int arr[NMAX], cp_arr[NMAX];
    int arr_len, cp_arr_len;

    printf("Enter number of elements in the array: ");
    if (scanf("%d", &arr_len) != 1 || arr_len <= 0 || arr_len > 10)
    {
        printf("Input error.");
        return 1;
    }

    if (read_array(arr, arr_len))
    {
        printf("Input error.");
        return 1;
    }

    cp_arr_len = prime_copy(cp_arr, arr, arr_len);

    if (cp_arr_len <= 0)
    {
        printf("There aren't prime numbers in the given array.\n");
        return 1;
    }

    printf("Elements of the new array:");
    for (int i = 0; i < cp_arr_len; ++i)
        printf(" %d", cp_arr[i]);

    return 0;
}

int is_prime(int number)
{
    if (number <= 0 || number == 1)
        return 0;

    if (number == 2)
        return 1;

    for (int i = 2; i < sqrt(number) + 1; ++i)
    {
        if (number % i == 0)
            return 0;
    }

    return 1;
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

int prime_copy(int *dst, int *src, int src_len)
{
    int dst_len = 0;

    for (int i = 0; i < src_len; ++i)
        if (is_prime(src[i]))
            dst[dst_len++] = src[i];

    return dst_len;
}
