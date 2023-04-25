#include "my_string.h"
#include <stddef.h>

char *my_strpbrk(char *s, char *accept)
{
    size_t i = 0;
    size_t j = 0;

    while (s[i] != '\0')
    {
        while (accept[j] != '\0')
        {
            if (s[i] == accept[j])
                return s;
            ++j;
        }
        ++i;
    }

    return NULL;
}

size_t my_strspn(char *s, char *accept)
{
    size_t n = 0;
    size_t j = 0;

    while (s[j] != '\0')
    {
        size_t i = 0;
        while (accept[i] != '\0')
            if (s[j] == accept[i++])
            {
                ++n;
                break;
            }
        ++j;
    }

    return n;
}

size_t my_strcspn(char *s, char *reject)
{
    size_t n = 0;
    size_t j = 0;

    while (s[j] != '\0')
    {
        size_t i = 0;
        while (reject[i] != '\0')
            if (s[j] == reject[i++])
            {
                ++n;
                break;
            }
        ++j;
    }

    return j - n;
}

char *my_strchr(char *s, int c)
{
    size_t i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            return &s[i];
        ++i;
    }

    if (c == '\0')
        return &s[i];

    return NULL;
}

char *my_strrchr(char *s, int c)
{
    char *p = NULL;
    size_t i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == c)
            p = &s[i];
        ++i;
    }

    if (c == '\0')
        return &s[i];

    return p;
}
