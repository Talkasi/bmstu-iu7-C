#include "my_file.h"
#include <stdio.h>

#define NO_FILE_ERROR 1
#define FILE_OPEN_ERROR 2
#define READING_ERROR 3
#define NO_NUMS_COMPUTE_ERROR 4

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Error. No file to read from.\n");
        return NO_FILE_ERROR;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Error. Can't open the file.\n");
        return FILE_OPEN_ERROR;
    }

    size_t min_pos, max_pos;
    if (find_extremums_pos(f, &min_pos, &max_pos))
    {
        printf("Error while reading from file.\n");
        return READING_ERROR;
    }

    if (min_pos > max_pos)
    {
        int temp = min_pos;
        min_pos = max_pos;
        max_pos = temp;
    }

    min_pos += 1;
    max_pos -= 1;
    if (min_pos > max_pos)
    {
        printf("There are no numbers between min and max.\n");
        return NO_NUMS_COMPUTE_ERROR;
    }

    double avrg;
    if (average(f, &avrg, min_pos, max_pos))
    {
        printf("Error while reading from file.\n");
        return READING_ERROR;
    }

    printf("%lf\n", avrg);
    fclose(f);
    return 0;
}
