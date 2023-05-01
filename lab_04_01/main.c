#include "my_string.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    int n_errors = 0;

    {
        char *s[] = { "", " ", "", "char", "charchar", "char", "1222224", "123", "quqareque" };
        char *temp_s[] = { "", " ", "", "char", "charchar", "char", "1222224", "123", "quqareque" };

        char *param[] = { "", "", "char", "c", "h", "?", "229", "32", "q" };
        char *temp_param[] = { "", "", "char", "c", "h", "?", "229", "32", "q" };

        /* my_strpbrk testing */
        for (size_t i = 0; i < sizeof(s) / sizeof(char *); ++i)
        {
            char *my_res = my_strpbrk(s[i], param[i]);
            char *res = strpbrk(s[i], param[i]);

            size_t n_s = 0;
            size_t n_param = 0;

            for (size_t j = 0; j < sizeof(s) / sizeof(char *); ++j)
            {
                if (strcmp(s[j], temp_s[j]) != 0)
                    ++n_s;

                if (strcmp(param[j], temp_param[j]) != 0)
                    ++n_param;
            }

            if (my_res != res || n_s || n_param)
            {
                printf(">> Error in my_strpbrk\nInput parameters: %20s %20s\n", s[i], param[i]);
                printf("Submitted:        %20s\nExpected:         %20s\n", my_res, res);
                printf("`s` parameter was changed %zu times\n`param` parameter was changed %zu times\n", n_s, n_param);

                ++n_errors;
            }
        }
    }

    {
        char *s[] = { "", " ", "", "char", "charchar", "char", "1222224", "222224" };
        char *temp_s[] = { "", " ", "", "char", "charchar", "char", "1222224", "222224" };

        char *param[] = { "", "", "char", "char", "char", "?", "229", "32" };
        char *temp_param[] = { "", "", "char", "char", "char", "?", "229", "32" };

        /* my_strspn testing */
        for (size_t i = 0; i < sizeof(s) / sizeof(char *); ++i)
        {
            size_t my_res = my_strspn(s[i], param[i]);
            size_t res = strspn(s[i], param[i]);

            size_t n_s = 0;
            size_t n_param = 0;

            for (size_t j = 0; j < sizeof(s) / sizeof(char *); ++j)
            {
                if (strcmp(s[j], temp_s[j]) != 0)
                    ++n_s;

                if (strcmp(param[j], temp_param[j]) != 0)
                    ++n_param;
            }

            if (my_res != res || n_s || n_param)
            {
                printf(">> Error in my_strspn\nInput parameters: %20s %20s\n", s[i], param[i]);
                printf("Submitted:        %20zu\nExpected:         %20zu\n", my_res, res);
                printf("`s` parameter was changed %zu times\n`param` parameter was changed %zu times\n", n_s, n_param);

                ++n_errors;
            }
        }
    }

    {
        char *s[] = { "", " ", "", "char", "charchar", "char", "1222224", "123", "quqareque" };
        char *temp_s[] = { "", " ", "", "char", "charchar", "char", "1222224", "123", "quqareque" };

        char *param[] = { "", "", "char", "gc", "char", "?", "229", "32", "hjrl" };
        char *temp_param[] = { "", "", "char", "gc", "char", "?", "229", "32", "hjrl" };

        /* my_strcspn testing */
        for (size_t i = 0; i < sizeof(s) / sizeof(char *); ++i)
        {
            size_t my_res = my_strcspn(s[i], param[i]);
            size_t res = strcspn(s[i], param[i]);

            size_t n_s = 0;
            size_t n_param = 0;

            for (size_t j = 0; j < sizeof(s) / sizeof(char *); ++j)
            {
                if (strcmp(s[j], temp_s[j]) != 0)
                    ++n_s;

                if (strcmp(param[j], temp_param[j]) != 0)
                    ++n_param;
            }

            if (my_res != res || n_s || n_param)
            {
                printf(">> Error in my_strcspn\nInput parameters: %20s %20s\n", s[i], param[i]);
                printf("Submitted:        %20zu\nExpected:         %20zu\n", my_res, res);
                printf("`s` parameter was changed %zu times\n`param` parameter was changed %zu times\n", n_s, n_param);

                ++n_errors;
            }
        }
    }

    {
        char *s[] = { "", " ", "", "char", "charchar", "char", "1222224", "123", "quqareque" };
        char *temp_s[] = { "", " ", "", "char", "charchar", "char", "1222224", "123", "quqareque" };

        char c[] = { '\0', ' ', 'b', 'a', 'r', 'c', '2', '7', 'q' };
        char temp_c[] = { '\0', ' ', 'b', 'a', 'r', 'c', '2', '7', 'q' };

        /* my_strchr testing */
        for (size_t i = 0; i < sizeof(s) / sizeof(char *); ++i)
        {
            char *my_res = my_strchr(s[i], c[i]);
            char *res = strchr(s[i], c[i]);

            size_t n_s = 0;
            size_t n_c = 0;

            for (size_t j = 0; j < sizeof(s) / sizeof(char *); ++j)
            {
                if (strcmp(s[j], temp_s[j]) != 0)
                    ++n_s;

                if (c[j] != temp_c[j])
                    ++n_c;
            }

            if (my_res != res || n_s || n_c)
            {
                printf(">> Error in my_strchr\nInput parameters: %20s %20c\n", s[i], c[i]);
                printf("Submitted:        %20s\nExpected:         %20s\n", my_res, res);
                printf("`s` parameter was changed %zu times\n`c` parameter was changed %zu times\n", n_s, n_c);

                ++n_errors;
            }
        }
    }

    {
        char *s[] = { "", " ", "", "char", "charchar", "char", "1222224", "123", "quqareque" };
        char *temp_s[] = { "", " ", "", "char", "charchar", "char", "1222224", "123", "quqareque" };

        char c[] = { '\0', ' ', 'b', 'a', 'r', 'c', '2', '7', 'q' };
        char temp_c[] = { '\0', ' ', 'b', 'a', 'r', 'c', '2', '7', 'q' };

        /* my_strrchr testing */
        for (size_t i = 0; i < sizeof(s) / sizeof(char *); ++i)
        {
            char *my_res = my_strrchr(s[i], c[i]);
            char *res = strrchr(s[i], c[i]);

            size_t n_s = 0;
            size_t n_c = 0;

            for (size_t j = 0; j < sizeof(s) / sizeof(char *); ++j)
            {
                if (strcmp(s[j], temp_s[j]) != 0)
                    ++n_s;

                if (c[j] != temp_c[j])
                    ++n_c;
            }

            if (my_res != res || n_s || n_c)
            {
                printf(">> Error in my_strchr\nInput parameters: %20s %20c\n", s[i], c[i]);
                printf("Submitted:        %20s\nExpected:         %20s\n", my_res, res);
                printf("`s` parameter was changed %zu times\n`c` parameter was changed %zu times\n", n_s, n_c);

                ++n_errors;
            }
        }
    }

    printf("Number of errors: %d\n", n_errors);

    return n_errors;
}
