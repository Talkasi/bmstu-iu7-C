#include "my_string.h"
#include <stdio.h>
#include <string.h>

#define N_TESTS 8

int main(void)
{
    int n_errors = 0;

    char *s[N_TESTS] = { "", " ", "", "char", "charchar", "char", "1222224", "123" };
    char *param[N_TESTS] = { "", "", "char", "char", "char", "?", "229", "32" };
    char c[N_TESTS] = { '\0', ' ', 'b', 'a', 'r', 'c', '9', '1' };

    {
        /* my_strpbrk testing */
        for (size_t i = 0; i < N_TESTS; ++i)
        {
            char *my_res = my_strpbrk(s[i], param[i]);
            char *res = strpbrk(s[i], param[i]);

            if (my_res != res)
            {
                printf(">> Error in my_strpbrk\nInput parameters: %20s %20s\n", s[i], param[i]);
                printf("Submitted:        %20s\nExpected:         %20s\n", my_res, res);

                ++n_errors;
            }
        }
    }

    {
        /* my_strspn testing */
        for (size_t i = 0; i < N_TESTS; ++i)
        {
            size_t my_res = my_strspn(s[i], param[i]);
            size_t res = strspn(s[i], param[i]);

            if (my_res != res)
            {
                printf(">> Error in my_strspn\nInput parameters: %20s %20s\n", s[i], param[i]);
                printf("Submitted:        %20zu\nExpected:         %20zu\n", my_res, res);

                ++n_errors;
            }
        }
    }

    {
        /* my_strcspn testing */
        for (size_t i = 0; i < N_TESTS; ++i)
        {
            size_t my_res = my_strcspn(s[i], param[i]);
            size_t res = strcspn(s[i], param[i]);

            if (my_res != res)
            {
                printf(">> Error in my_strcspn\nInput parameters: %20s %20s\n", s[i], param[i]);
                printf("Submitted:        %20zu\nExpected:         %20zu\n", my_res, res);

                ++n_errors;
            }
        }
    }

    {
        /* my_strchr testing */
        for (size_t i = 0; i < N_TESTS; ++i)
        {
            char *my_res = my_strchr(s[i], c[i]);
            char *res = strchr(s[i], c[i]);

            if (my_res != res)
            {
                printf(">> Error in my_strchr\nInput parameters: %20s %20c\n", s[i], c[i]);
                printf("Submitted:        %20s\nExpected:         %20s\n", my_res, res);

                ++n_errors;
            }
        }
    }

    {
        /* my_strrchr testing */
        for (size_t i = 0; i < N_TESTS; ++i)
        {
            char *my_res = my_strrchr(s[i], c[i]);
            char *res = strrchr(s[i], c[i]);

            if (my_res != res)
            {
                printf(">> Error in my_strrchr\nInput parameters: %20s %20c\n", s[i], c[i]);
                printf("Submitted:        %20s\nExpected:         %20s\n", my_res, res);

                ++n_errors;
            }
        }
    }

    printf("Number of errors: %d\n", n_errors);

    return n_errors;
}
