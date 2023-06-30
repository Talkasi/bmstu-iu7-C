#include "my_string.h"
#include <stdio.h>

#define INPUT_LINE_ERROR 1

int main(void)
{
    char s[MAX_STR_LEN];
    if (line_scan(s) == MAX_STR_LEN + 1)
        return INPUT_LINE_ERROR;

    if (is_real(s))
        printf("YES");
    else
        printf("NO");

    return 0;
}
