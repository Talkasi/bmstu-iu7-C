#include <stdio.h>

#define NMAX 10
#define ERROR -1

int read_array(int *arr);
void print_array(int *arr, int arr_len);
void bubble_sort(int *arr, int arr_len);

int main(void)
{
    int arr[NMAX];
    int arr_len, ret_code = 0;

    printf("Enter elements of an array:\n");
    if ((arr_len = read_array(arr)) == ERROR)
    {
        printf("Input error.");
        return 1;
    }

    if (arr_len == 100)
    {
        ret_code = 100;
        arr_len = 10;
    }

    bubble_sort(arr, arr_len);
    print_array(arr, arr_len);

    return ret_code;
}

void bubble_sort(int *arr, int arr_len)
{
    int temp;

    for (int i = 0; i < arr_len; ++i)
        for (int j = 0; j < i; ++j)
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

int read_array(int *arr)
{
    int i = 0, temp;

    while (scanf("%d", &temp) == 1)
    {
        if (i >= NMAX)
            return 100;
        arr[i++] = temp;
    }

    if (i == 0)
        return ERROR;

    return i;
}

void print_array(int *arr, int arr_len)
{
    printf("Elements of the array:");
    for (int i = 0; i < arr_len; ++i)
        printf(" %d", arr[i]);
}
