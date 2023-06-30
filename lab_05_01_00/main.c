#include "my_file.h"
#include <stdio.h>

int main(void)
{
    int max;
    int rc;

    printf("Enter numbers: ");
    if ((rc = process(stdin, &max)))
        return rc;

    fprintf(stdout, "%d\n", max);
    return 0;
}
