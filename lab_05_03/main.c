#include "my_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO_PARAMETERS_ERROR 1
#define WRONG_PARAMETERS_ERROR 2
#define FILE_OPEN_ERROR 3
#define READING_ERROR 4

enum keys
{
    C,
    P,
    S
};

int valid_param(char *key, int *state);

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Error. Not enough parameters.\n");
        return NO_PARAMETERS_ERROR;
    }

    int state;
    if (!valid_param(argv[1], &state))
    {
        printf("Error. Wrong parameters.\n");
        return WRONG_PARAMETERS_ERROR;
    }

    if (state == C)
    {
        if (argc < 4)
        {
            printf("Error. Not enough parameters.\n");
            return NO_PARAMETERS_ERROR;
        }

        FILE *f = fopen(argv[3], "wb");
        rand_fill(f, atoi(argv[2]));
        fclose(f);
    }

    if (state == P)
    {
        FILE *f = fopen(argv[2], "rb");
        if (f == NULL)
        {
            printf("Error. Can't open the file.\n");
            return FILE_OPEN_ERROR;
        }

        print(f);
        fclose(f);
    }

    if (state == S)
    {
        FILE *f = fopen(argv[2], "rb+");
        if (f == NULL)
        {
            printf("Error. Can't open the file.\n");
            return FILE_OPEN_ERROR;
        }

        bubble_sort(f);
        fclose(f);
    }

    return 0;
}

int valid_param(char *key, int *state)
{
    char *valid_keys[] = { "c", "p", "s" };

    for (size_t i = 0; i < sizeof(valid_keys) / sizeof(char *); ++i)
        if (strcmp(key, valid_keys[i]) == 0)
        {
            *state = (int)i;
            return 1;
        }

    return 0;
}
