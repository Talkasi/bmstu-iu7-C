#include <stdio.h>

#define NMAX 10

int main(void)
{
    long arr[NMAX];
    int n, n_odd = 0;
    long long p = 1;

    printf("Enter number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 10)
    {
        printf("Input error.");
        return 1;
    }

    for (int i = 0; i < n; ++i)
    {
        printf("Enter element of an array: ");
        if (scanf("%ld", &arr[i]) != 1)
        {
            printf("Input error.");
            return 1;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (arr[i] % 2 != 0)
        {
            ++n_odd;
            p *= arr[i];
        }
    }

    if (n_odd > 0)
    {
        printf("The product of odd array elements is: %lld", p);
        return 0;
    }
    else
    {
        printf("There aren't odd elements in an array.");
        return 1;
    }
}
