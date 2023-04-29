#include "my_string.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int digits_skip(char *s, size_t *cur_i);

int line_scan(char *s)
{
    char temp_s[MAX_STR_LEN + 1];
    char *temp_p = fgets(temp_s, MAX_STR_LEN + 1, stdin);

    if (temp_p == NULL || temp_s[0] == '\n')
        return 0;

    size_t len_temp_s = strlen(temp_s);
    if (len_temp_s == MAX_STR_LEN && temp_s[len_temp_s - 1] != '\n')
        return 0;

    if (temp_s[len_temp_s - 1] == '\n')
        temp_s[--len_temp_s] = '\0';

    strcpy(s, temp_s);

    return len_temp_s;
}

int is_real(char *s)
{
    /* [+-]?(\d+([.]\d*)?([eE][+-]?\d+)?|[.]\d+([eE][+-]?\d+)?) */
    size_t i = 0;
    int cur_state = 1;

    while (isspace(s[i]))
        ++i;

    /* [+-]? */
    if (s[i] == '+' || s[i] == '-')
        ++i;

    size_t word_start = i;

    /* \d+ */
    if (digits_skip(s, &i) == 0)
        cur_state = 0;

    /* ([.]\d*)? */
    if (s[i] == '.')
    {
        ++i;

        digits_skip(s, &i);
    }

    /* ([eE][+-]?\d+)? */
    if (s[i] == 'e' || s[i] == 'E')
    {
        ++i;
        if (s[i] == '+' || s[i] == '-')
            ++i;

        if (digits_skip(s, &i) == 0)
            cur_state = 0;
    }

    if (cur_state == 0)
    {
        i = word_start;

        /* [.]\d+ */
        if (s[i] == '.')
        {
            ++i;

            if (digits_skip(s, &i) == 0)
                return 0;
        }
        else
            return 0;

        /* ([eE][+-]?\d+)? */
        if (s[i] == 'e' || s[i] == 'E')
        {
            ++i;
            if (s[i] == '+' || s[i] == '-')
                ++i;

            if (digits_skip(s, &i) == 0)
                return 0;
        }
    }

    while (isspace(s[i]))
        ++i;

    return s[i] == '\0';
}

int digits_skip(char *s, size_t *cur_i)
{
    size_t temp = *cur_i;
    while (isdigit(s[*cur_i]))
        ++*cur_i;

    if (*cur_i == temp)
        return 0;

    return 1;
}
