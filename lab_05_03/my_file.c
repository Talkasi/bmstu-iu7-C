#include "my_file.h"
#include <stdlib.h>
#include <time.h>

int rand_fill(FILE *f, size_t n_numbers)
{
    fseek(f, 0, SEEK_SET);
    my_type rands[BUFSIZ];
    srand(time(NULL));
    int rc;

    for (size_t i = 1; i <= n_numbers; ++i)
    {
        rands[i - 1] = rand();
        if (i == n_numbers || i == BUFSIZ)
            fwrite(rands, sizeof(my_type), i % BUFSIZ, f);

        if ((rc = ferror(f)))
            return rc;
    }

    return 0;
}

int print_nums(FILE *f)
{
    fseek(f, 0, SEEK_SET);
    my_type number;

    while (fread(&number, sizeof(my_type), 1, f) == 1)
        printf("%" PRId32 " ", number);

    return ferror(f);
}

my_type get_number_by_pos(FILE *f, size_t pos)
{
    fseek(f, pos * sizeof(my_type), SEEK_SET);
    my_type number;
    fread(&number, sizeof(my_type), 1, f);
    return number;
}

void put_number_by_pos(FILE *f, my_type number, size_t pos)
{
    fseek(f, pos * sizeof(my_type), SEEK_SET);
    fwrite(&number, sizeof(my_type), 1, f);
}

void bubble_sort(FILE *f)
{
    fseek(f, 0, SEEK_SET);
    for (size_t i = 0; i < file_size(f) / sizeof(my_type); ++i)
        for (size_t j = 0; j < i; ++j)
        {
            my_type a = get_number_by_pos(f, i);
            my_type b = get_number_by_pos(f, j);
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
