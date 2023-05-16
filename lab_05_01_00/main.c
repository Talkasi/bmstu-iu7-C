#include "my_file.h"
#include <stdio.h>

#define READING_ERROR 1
#define NO_MAX_ERROR 2

int main(void)
{
    int max;
    printf("Enter numbers: ");
    if (process(stdin, &max))
    {
        printf("Error while reading from file.\n");
        return READING_ERROR;
    }

    if (max < 0)
    {
        printf("Error. There is no positives after negatives.\n");
        return NO_MAX_ERROR;
    }

    printf("%d\n", max);
    return 0;
}
