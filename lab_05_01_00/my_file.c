#include "my_file.h"

int process(FILE *f, int *max)
{
    int number;
    int were_neg = 0;
    *max = -1;

    while (fscanf(f, "%d", &number) == 1)
    {
        if (were_neg && *max < number)
            *max = number;

        if (number < 0)
            were_neg = 1;
    }

    return ferror(f);
}
