#include "my_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PARAMETERS_N_ERROR 1
#define WRONG_PARAMETERS_ERROR 2

#define FILE_OPEN_ERROR 3
#define FILE_SIZE_ERROR 4
#define PRINTING_ERROR 5
#define SORTING_ERROR 6

/*
 * Usage:
- `n file`: fill binary `file` with `n` numbers, where n itself is a number
- `p file`: print numbers from binary `file`
- `s file`: sort numbers in binary `file`
 *
 * Used int type: int32_t
 * Note: It is more safe to use int32_t when working with binary files,
 * because it makes program more portable.
 *
 * Sorting algorithm used: bubble sort in increasing order.
 */
int main(int argc, char *argv[])
{
    if (argc != 3)
        return PARAMETERS_N_ERROR;

    int number;
    if ((number = atoi(argv[1])) && number > 0)
    {
        FILE *f = fopen(argv[2], "wb");
        if (f == NULL)
            return FILE_OPEN_ERROR;

        rand_fill(f, number);
        fclose(f);
    }
    else if (strcmp(argv[1], "p") == 0)
    {
        FILE *f = fopen(argv[2], "rb");
        if (f == NULL)
            return FILE_OPEN_ERROR;

        size_t fsize = file_size(f);
        if (fsize == 0 || fsize % sizeof(my_type) != 0)
        {
            fclose(f);
            return FILE_SIZE_ERROR;
        }

        int rc = print_nums(f);
        fclose(f);

        if (rc)
            return PRINTING_ERROR;
    }
    else if (strcmp(argv[1], "s") == 0)
    {
        FILE *f = fopen(argv[2], "rb+");
        if (f == NULL)
            return FILE_OPEN_ERROR;

        size_t fsize = file_size(f);
        if (fsize == 0 || fsize % sizeof(my_type) != 0)
        {
            fclose(f);
            return FILE_SIZE_ERROR;
        }

        int rc = bubble_sort(f);
        fclose(f);
        if (rc)
            return SORTING_ERROR;
    }
    else
        return WRONG_PARAMETERS_ERROR;

    return 0;
}
