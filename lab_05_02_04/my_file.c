#include "my_file.h"

int find_extremums_pos(FILE *f, size_t *min_pos, size_t *max_pos)
{
    fseek(f, 0, SEEK_SET);
    double cur_number;
    if (fscanf(f, "%lf", &cur_number) != 1)
        return -1;

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

    return ferror(f);
}

int average(FILE *f, double *avrg, size_t start_pos, size_t end_pos)
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

    *avrg /= (end_pos - start_pos + 1);

    return ferror(f);
}
