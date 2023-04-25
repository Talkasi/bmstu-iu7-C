#include "my_string.h"
#include <stddef.h>

char *my_strpbrk(const char *s, const char *accept)
{
    size_t i = 0;

    while (s[i] != '\0')
    {
        size_t j = 0;
        while (accept[j] != '\0')
            if (s[i] == accept[j++])
                return (char *)&s[i];

        ++i;
    }

    return NULL;
}

size_t my_strspn(const char *s, const char *accept)
{
    size_t n = 0;
    size_t j;

    for (size_t i = 0; s[i] != '\0'; ++i)
    {
        for (j = 0; accept[j] != '\0'; ++j)
            if (s[i] == accept[j])
            {
                ++n;
                break;
            }

        if (accept[j] == '\0')
            break;
    }

    return n;
}

size_t my_strcspn(const char *s, const char *reject)
{
    size_t n = 0;

    for (size_t i = 0; s[i] != '\0'; ++i)
    {
        for (size_t j = 0; reject[j] != '\0'; ++j)
            if (s[i] == reject[j])
                return n;

        ++n;
    }

    return n;
}

char *my_strchr(const char *s, int c)
{
    size_t i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            return (char *)&s[i];
        ++i;
    }

    if (c == '\0')
        return (char *)&s[i];

    return NULL;
}

char *my_strrchr(const char *s, int c)
{
    char *p = NULL;
    size_t i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == c)
            p = (char *)&s[i];
        ++i;
    }

    if (c == '\0')
        return (char *)&s[i];

    return p;
}
