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

int get_number_by_pos(FILE *f, my_type *num, size_t pos)
{
    fseek(f, pos * sizeof(my_type), SEEK_SET);
    return (fread(num, sizeof(my_type), 1, f) != 1);
}

int put_number_by_pos(FILE *f, my_type num, size_t pos)
{
    fseek(f, pos * sizeof(my_type), SEEK_SET);
    return (fwrite(&num, sizeof(my_type), 1, f) != 1);
}

int bubble_sort(FILE *f)
{
    fseek(f, 0, SEEK_SET);
    for (size_t i = 0; i < file_size(f) / sizeof(my_type); ++i)
        for (size_t j = 0; j < i; ++j)
        {
            my_type a, b;
            if (get_number_by_pos(f, &a, i) || get_number_by_pos(f, &b, j))
                return 1;

            if (a < b)
                if (put_number_by_pos(f, a, j) || put_number_by_pos(f, b, i))
                    return 1;
        }

    return 0;
}

size_t file_size(FILE *f)
{
    fseek(f, 0, SEEK_END);
    return ftell(f);
}
