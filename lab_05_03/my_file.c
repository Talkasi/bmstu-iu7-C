#include "my_file.h"
#include <stdlib.h>

void rand_fill(FILE *f, size_t n_numbers)
{
    fseek(f, 0, SEEK_SET);
    int rands[BUFSIZ];

    for (size_t i = 1; i <= n_numbers; ++i)
    {
        rands[i - 1] = rand();
        if (i == n_numbers || i == BUFSIZ)
            fwrite(rands, sizeof(int), i % BUFSIZ, f);
    }
}

void print(FILE *f)
{
    fseek(f, 0, SEEK_SET);
    int number;

    while (fread(&number, sizeof(int), 1, f) == 1)
        printf("%d ", number);
}

int get_number_by_pos(FILE *f, size_t pos)
{
    fseek(f, pos * sizeof(int), SEEK_SET);
    int number;
    fread(&number, sizeof(int), 1, f);
    return number;
}

void put_number_by_pos(FILE *f, int number, size_t pos)
{
    fseek(f, pos * sizeof(int), SEEK_SET);
    fwrite(&number, sizeof(int), 1, f);
}

void bubble_sort(FILE *f)
{
    fseek(f, 0, SEEK_SET);
    for (size_t i = 0; i < file_size(f) / sizeof(int); ++i)
        for (size_t j = 0; j < i; ++j)
        {
            int a = get_number_by_pos(f, i);
            int b = get_number_by_pos(f, j);
            if (a < b)
            {
                put_number_by_pos(f, a, j);
                put_number_by_pos(f, b, i);
            }
        }
}

size_t file_size(FILE *f)
{
    fseek(f, 0, SEEK_END);
    return ftell(f);
}
