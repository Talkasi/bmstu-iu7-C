#include <stdio.h>

#define NMAX 10

int read_array(int arr[], int arr_len);
int odd_product(int arr[], int arr_len);

int main(void)
{
    int arr[NMAX];
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

    int p = odd_product(arr, arr_len);
    if (p == 0)
    {
        printf("There aren't odd elements in an array.");
        return 1;
    }

    printf("The product of odd array elements is: %d", p);
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

int odd_product(int arr[], int arr_len)
{
    int p = 1;
    int n_odd = 0;

    for (int i = 0; i < arr_len; ++i)
    {
        if (arr[i] % 2 != 0)
        {
            ++n_odd;
            p *= arr[i];
        }
    }

    if (n_odd == 0)
        return 0;

    return p;
}
