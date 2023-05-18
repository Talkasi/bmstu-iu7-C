#include "my_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PARAMETERS_N_ERROR 1
#define WRONG_PARAMETERS_ERROR 2
#define WRONG_NUMBER_KEY_ERROR 3

#define FILE_OPEN_ERROR 4
#define FILE_SIZE_ERROR 5
#define PRINTING_ERROR 6

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error. Wrong number of parameters.\n");
        return PARAMETERS_N_ERROR;
    }

    int number;
    if ((number = atoi(argv[1])))
    {
        FILE *f = fopen(argv[2], "wb");
        if (number <= 0)
        {
            printf("Error. Wrong amount of numbers to fill a file.\n");
            return WRONG_NUMBER_KEY_ERROR;
        }
        rand_fill(f, number);
        fclose(f);
    }
    else if (strcmp(argv[1], "p") == 0)
    {
        FILE *f = fopen(argv[2], "rb");
        if (f == NULL)
        {
            printf("Error. Can't open the file.\n");
            return FILE_OPEN_ERROR;
        }

        size_t fsize = file_size(f);
        if (fsize == 0 || fsize % sizeof(int) != 0)
        {
            printf("Error. Wrong file size.\n");
            return FILE_SIZE_ERROR;
        }

        if (print(f))
        {
            printf("Error while printing.\n");
            return PRINTING_ERROR;
        }
        fclose(f);
    }
    else if (strcmp(argv[1], "s") == 0)
    {
        FILE *f = fopen(argv[2], "rb+");
        if (f == NULL)
        {
            printf("Error. Can't open the file.\n");
            return FILE_OPEN_ERROR;
        }

        size_t fsize = file_size(f);
        if (fsize == 0 || fsize % sizeof(int) != 0)
        {
            printf("Error. Wrong file size.\n");
            return FILE_SIZE_ERROR;
        }

        bubble_sort(f);
        fclose(f);
    }
    else
    {
        printf("Error. Unknown parameters.\n");
        return WRONG_PARAMETERS_ERROR;
    }

    return 0;
}