#include "my_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PARAMETERS_N_ERROR 1
#define WRONG_PARAMETERS_ERROR 2

#define FILE_OPEN_ERROR 3
#define FILE_SIZE_ERROR 4
#define PRINTING_ERROR 5

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

        int rc = print(f);
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

        bubble_sort(f);
        fclose(f);
    }
    else
        return WRONG_PARAMETERS_ERROR;

    return 0;
}
