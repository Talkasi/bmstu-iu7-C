#include <stdio.h>

#define NMAX 10

int read_array(int *arr_first, int *arr_past_last);
int count_uniq(int *arr_first, int *arr_past_last);
int check_presence(int *arr_first, int *arr_past_last);

int main(void)
{
    int a[NMAX];
    int *arr = a;
    int arr_len;

    printf("Enter number of elements in the array: ");
    if (scanf("%d", &arr_len) != 1 || arr_len <= 0 || arr_len > NMAX)
    {
        printf("Input error.");
        return 1;
    }

    printf("Enter elements of an array:\n");
    if (read_array(arr, arr + arr_len))
    {
        printf("Input error.");
        return 1;
    }

    printf("There are %d uniq elements in the array.\n", count_uniq(arr, arr + arr_len));

    return 0;
}

int read_array(int *arr_first, int *arr_past_last)
{
    int *arr_cur = arr_first;
    while (arr_cur < arr_past_last)
    {
        if (scanf("%d", arr_cur) != 1)
            return 1;

        arr_cur++;
    }

    return 0;
}

int count_uniq(int *arr_first, int *arr_past_last)
{
    int n_uniq = 0;

    for (int *arr_cur = arr_first; arr_cur < arr_past_last; ++arr_cur)
        if (!check_presence(arr_first, arr_cur))
            ++n_uniq;

    return n_uniq;
}

int check_presence(int *arr_first, int *arr_past_last)
{
    for (int *arr_cur = arr_first; arr_cur < arr_past_last; ++arr_cur)
        if (*arr_cur == *arr_past_last)
            return 1;

    return 0;
}
