#include "my_string.h"
#include <stdio.h>

#define MAX_STR_LEN 257

int main(void)
{
    char s[MAX_STR_LEN];
    if (!line_scan(s, MAX_STR_LEN))
        return 1;

    if (is_real(s))
        printf("YES");
    else
        printf("NO");

    return 0;
}
