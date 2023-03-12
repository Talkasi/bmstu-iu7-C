#include <math.h>
#include <stdio.h>

#define NMAX 10

int is_prime(long number);

int main(void)
{
    long arr[NMAX], cp_arr[NMAX];
    int len_arr, len_cp_arr = 0;
    int i;

    printf("Enter number of elements in the array: ");
    if (scanf("%d", &len_arr) != 1 || len_arr <= 0 || len_arr > 10)
    {
        printf("Input error.");
        return 1;
    }

    for (i = 0; i < len_arr; ++i)
    {
        printf("Enter element of an array: ");
        if (scanf("%ld", &arr[i]) != 1)
        {
            printf("Input error.");
            return 1;
        }
    }

    for (i = 0; i < len_arr; ++i)
        if (is_prime(arr[i]))
            cp_arr[len_cp_arr++] = arr[i];

    if (len_cp_arr > 0)
    {
        printf("Elements of the new array:");
        for (int i = 0; i < len_cp_arr; ++i)
            printf(" %ld", cp_arr[i]);

        return 0;
    }
    else
    {
        printf("There aren't prime numbers in the given array.\n");
        return 1;
    }
}

int is_prime(long number)
{
    if (number == 1)
        return 0;

    if (number == 2)
        return 1;

    for (long i = 2; i < sqrt(number) + 1; ++i)
    {
        if (number % i == 0)
            return 0;
    }

    return 1;
}
