#include "my_file.h"
#include <stdio.h>

#define NO_FILE_ERROR 1
#define FILE_OPEN_ERROR 2
#define NO_NUMS_COMPUTE_ERROR 3

int main(int argc, char *argv[])
{
    if (argc < 2)
        return NO_FILE_ERROR;

    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
        return FILE_OPEN_ERROR;

    size_t min_pos, max_pos;
    int rc;
    if ((rc = extremums_pos(f, &min_pos, &max_pos)))
    {
        fclose(f);
        return rc;
    }

    if ((rc = bounds_correct(&min_pos, &max_pos)))
    {
        fclose(f);
        return rc;
    }

    double average;
    if (avrg(f, &average, min_pos, max_pos))
    {
        fclose(f);
        return READING_ERROR;
    }

    printf("Average: %lf\n", average);
    fclose(f);
    return 0;
}
