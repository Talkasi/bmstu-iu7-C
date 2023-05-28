#include "my_file.h"

int extremums_pos(FILE *f, size_t *min_pos, size_t *max_pos)
{
    fseek(f, 0, SEEK_SET);
    double cur_number;
    if (fscanf(f, "%lf", &cur_number) != 1)
        return READING_ERROR;

    double min = cur_number;
    double max = cur_number;
    *max_pos = 0;
    *min_pos = 0;
    size_t i = 1;

    while (fscanf(f, "%lf", &cur_number) == 1)
    {
        if (max < cur_number)
        {
            max = cur_number;
            *max_pos = i;
        }

        if (min > cur_number)
        {
            min = cur_number;
            *min_pos = i;
        }
        ++i;
    }

    if (ferror(f))
        return READING_ERROR;

    return 0;
}

int bounds_correct(size_t *l_pos, size_t *r_pos)
{
    if (*l_pos > *r_pos)
    {
        int temp = *l_pos;
        *l_pos = *r_pos;
        *r_pos = temp;
    }

    *l_pos += 1;
    *r_pos -= 1;
    if (*l_pos > *r_pos)
        return WRONG_BOUNDS_ERROR;

    return 0;
}

int avrg(FILE *f, double *avrg, size_t start_pos, size_t end_pos)
{
    fseek(f, 0, SEEK_SET);
    double cur_number;
    size_t i = 0;
    *avrg = 0;

    while (fscanf(f, "%lf", &cur_number) == 1)
    {
        if (start_pos <= i && i <= end_pos)
            *avrg += cur_number;
        ++i;
    }

    if (ferror(f))
        return READING_ERROR;

    *avrg /= (end_pos - start_pos + 1);
    return 0;
}
