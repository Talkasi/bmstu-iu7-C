#include "my_string.h"
#include <stdio.h>
#include <string.h>

#define N_TESTS 7

int main(void)
{
    size_t n_errors = 0;

    char *s[N_TESTS] = { "", " ", "", "char", "charchar", "char", "1222224" };
    char *param[N_TESTS] = { "", "", "char", "char", "char", "?", "229" };
    char c[N_TESTS] = { '\0', ' ', 'b', 'a', 'r', 'c', '9' };

    {
        /* my_strpbrk testing */
        for (size_t i = 0; i < N_TESTS; ++i)
        {
            char *my_res = my_strpbrk(s[i], param[i]);
            char *res = strpbrk(s[i], param[i]);

            if (my_res != res)
            {
                printf(">> Error in my_strpbrk\n");
                printf("Input parameters: %20s %20s\n", s[i], param[i]);
                printf("Submitted:        %20s\n", my_res);
                printf("Expected:         %20s\n", res);

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
                printf(">> Error in my_strspn\n");
                printf("Input parameters: %20s %20s\n", s[i], param[i]);
                printf("Submitted:        %20zu\n", my_res);
                printf("Expected:         %20zu\n", res);

                ++n_errors;
            }
        }
    }

    {
        /* my_strspn testing */
        for (size_t i = 0; i < N_TESTS; ++i)
        {
            size_t my_res = my_strcspn(s[i], param[i]);
            size_t res = strcspn(s[i], param[i]);

            if (my_res != res)
            {
                printf(">> Error in my_strcspn\n");
                printf("Input parameters: %20s %20s\n", s[i], param[i]);
                printf("Submitted:        %20zu\n", my_res);
                printf("Expected:         %20zu\n", res);

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
                printf(">> Error in my_strchr\n");
                printf("Input parameters: %20s %20c\n", s[i], c[i]);
                printf("Submitted:        %20s\n", my_res);
                printf("Expected:         %20s\n", res);

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
                printf(">> Error in my_strcspn\n");
                printf("Input parameters: %20s %20c\n", s[i], c[i]);
                printf("Submitted:        %20s\n", my_res);
                printf("Expected:         %20s\n", res);

                ++n_errors;
            }
        }
    }

    printf("Number of errors: %zu\n", n_errors);

    return (int)n_errors;
}
