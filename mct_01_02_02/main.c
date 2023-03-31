#include <math.h>
#include <stdio.h>

#define N_MAX 1024
/*
Реализовать функцию-фильтр, сохраняющую в массиве целых чисел только полные квадраты.
 Реализовать функцию, которая ставит на место после каждого двузначного числа определённое число.
 Принять с клавиатуры число, принять с клавиатуры массив не более, чем из 1024 элементов, применить
 к нему первую и вторую функции и вывести результат на экран. К каждой функции указать описание в любом удобном формате.
*/

int arr_read(int arr[], size_t arr_len);
void arr_print(int arr[], size_t arr_len);
void my_filter(int arr[], size_t *arr_len);
void my_insertion(int number, int arr[], size_t *arr_len, int n_max);
void elem_insert(int number, int position, int arr[], size_t *arr_len, int n_max);

int main(void)
{
    size_t arr_len;
    int arr[N_MAX];
    int num;

    printf("Enter length of an array: ");
    if (scanf("%zu", &arr_len) != 1 || arr_len == 0 || arr_len > N_MAX)
    {
        printf("Input length error\n");
        return 1;
    }

    printf("Enter elements of an array:\n");
    if (arr_read(arr, arr_len))
    {
        printf("Input array error\n");
        return 1;
    }

    printf("Enter number to insert:\n");
    if (scanf("%d", &num) != 1)
    {
        printf("Input number error\n");
        return 1;
    }

    my_filter(arr, &arr_len);
    my_insertion(num, arr, &arr_len, N_MAX);

    arr_print(arr, arr_len);

    return 0;
}

int arr_read(int arr[], size_t arr_len)
{
    for (size_t i = 0; i < arr_len; ++i)
        if (scanf("%d", &arr[i]) != 1)
            return 1;

    return 0;
}

void arr_print(int arr[], size_t arr_len)
{
    for (size_t i = 0; i < arr_len; ++i)
        printf("%d ", arr[i]);
}

void my_filter(int arr[], size_t *arr_len)
{
    size_t j = 0;

    for (size_t i = 0; i < *arr_len; ++i)
    {
        int sq = sqrt(arr[i]);
        if (sq * sq == arr[i])
            arr[j++] = arr[i];
    }

    *arr_len = j;
}

void my_insertion(int number, int arr[], size_t *arr_len, int n_max)
{
    size_t i = 0;

    while (i < *arr_len)
    {
        if (arr[i] >= 10 && arr[i] < 100)
        {
            elem_insert(number, i + 1, arr, arr_len, n_max);
            ++i;
        }

        ++i;
    }
}

void elem_insert(int number, int position, int arr[], size_t *arr_len, int n_max)
{
    if (*arr_len + 1 > n_max)
        return;

    for (size_t i = *arr_len; i > position; --i)
        arr[i] = arr[i - 1];

    arr[position] = number;
    ++(*arr_len);
}
