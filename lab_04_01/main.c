#include "my_string.h"
#include <stdio.h>
#include <string.h>

#define N_TESTS 6

int main(void)
{
    size_t n_errors = 0;

    {
        /* my_strpbrk testing */
        char *s[N_TESTS] = {"", " ", "", "char", "charchar", "char"};
        char *accept[N_TESTS] = {"", "", "char", "char", "char", "?"};

        for (size_t i = 0; i < N_TESTS; ++i)
        {
            char *my_res = my_strpbrk(s[i], accept[i]);
            char *res = strpbrk(s[i], accept[i]);

            if (my_res != res)
            {
                printf(">> Error in my_strpbrk\n"
                       "Input parameters: %20s %20s\n"
                       "Submitted:        %20s\n"
                       "Expected:         %20s\n",
                       s[i], accept[i], my_res, res);
                ++n_errors;
            }
        }
    }

    {
        /* my_strspn testing */
        char *s[N_TESTS] = {"", " ", "", "char", "charchar", "char"};
        char *accept[N_TESTS] = {"", "", "char", "char", "char", "?"};

        for (size_t i = 0; i < N_TESTS; ++i)
        {
            size_t my_res = my_strspn(s[i], accept[i]);
            size_t res = strspn(s[i], accept[i]);

            if (my_res != res)
            {
                printf("\n>> Error in my_strspn\n"
                       "Input parameters: %20s %20s\n"
                       "Submitted:        %20zu\n"
                       "Expected:         %20zu\n",
                       s[i], accept[i], my_res, res);
                ++n_errors;
            }
        }
    }

    {
        /* my_strspn testing */
        char *s[N_TESTS] = {"", " ", "", "char", "charchar", "char"};
        char *reject[N_TESTS] = {"", "", "char", "char", "char", "?"};

        for (size_t i = 0; i < N_TESTS; ++i)
        {
            size_t my_res = my_strcspn(s[i], reject[i]);
            size_t res = strcspn(s[i], reject[i]);

            if (my_res != res)
            {
                printf("\n>> Error in my_strspn\n"
                       "Input parameters: %20s %20s\n"
                       "Submitted:        %20zu\n"
                       "Expected:         %20zu\n",
                       s[i], reject[i], my_res, res);
                ++n_errors;
            }
        }
    }

    {
        /* my_strchr testing */
        char *s[N_TESTS] = {"", " ", "", "char", "charchar", "char"};
        char c[N_TESTS] = {'\0', ' ', 'b', 'a', 'r', 'c'};

        for (size_t i = 0; i < N_TESTS; ++i)
        {
            char *my_res = my_strchr(s[i], c[i]);
            char *res = strchr(s[i], c[i]);

            if (my_res != res)
            {
                printf("\n>> Error in my_strchr\n"
                       "Input parameters: %20s %20c\n"
                       "Submitted:        %20s\n"
                       "Expected:         %20s\n",
                       s[i], c[i], my_res, res);
                ++n_errors;
            }
        }
    }

    {
        /* my_strrchr testing */
        char *s[N_TESTS] = {"", " ", "", "char", "charchar", "char"};
        char c[N_TESTS] = {'\0', ' ', 'b', 'a', 'r', 'c'};

        for (size_t i = 0; i < N_TESTS; ++i)
        {
            char *my_res = my_strrchr(s[i], c[i]);
            char *res = strrchr(s[i], c[i]);

            if (my_res != res)
            {
                printf("\n>> Error in my_strrchr\n"
                       "Input parameters: %20s %20c\n"
                       "Submitted:        %20s\n"
                       "Expected:         %20s\n",
                       s[i], c[i], my_res, res);
                ++n_errors;
            }
        }
    }

    printf("Number of errors: %zu\n", n_errors);

    return (int)n_errors;
}
