#include "my_file.h"

int process(FILE *f, int *max)
{
    int cur_num;
    int were_neg = 0;
    *max = 0;

    while (fscanf(f, "%d", &cur_num) == 1)
    {
        if (were_neg && *max < cur_num)
            *max = cur_num;

        were_neg = (cur_num < 0);
    }

    if (ferror(f))
        return READING_ERROR;

    if (*max == 0)
        return NO_MAX_ERROR;

    return 0;
}
