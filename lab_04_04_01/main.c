#include "my_string.h"
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 256

int main(void)
{
    char s[MAX_STR_LEN];
    if (fgets(s, MAX_STR_LEN, stdin) == NULL)
        return 1;

    size_t s_len = strlen(s);
    if (s[s_len - 1] == '\n')
        s[s_len - 1] = '\0';

    if (is_real(s))
        printf("YES");
    else
        printf("NO");

    return 0;
}
