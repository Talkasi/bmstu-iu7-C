#include "my_string.h"
#include <stdio.h>

int main(void)
{
    char s[MAX_STR_LEN];
    if (!line_scan(s))
        return 1;

    if (is_real(s))
        printf("YES");
    else
        printf("NO");

    return 0;
}
