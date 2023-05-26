#include "my_product.h"
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

size_t line_scan(FILE *f, char *s, size_t max_s_len)
{
    if (max_s_len > MAX_STR_LEN)
        return max_s_len + 1;

    char temp_s[MAX_STR_LEN + 1];
    char *temp_p = fgets(temp_s, MAX_STR_LEN + 1, f);

    if (temp_p == NULL)
    {
        s[0] = '\0';
        return 0;
    }

    size_t len_temp_s = strlen(temp_p);
    if ((len_temp_s == max_s_len + 1 && temp_s[len_temp_s - 1] != '\n') || len_temp_s > max_s_len)
        return max_s_len + 1;

    if (temp_s[len_temp_s - 1] == '\n')
        temp_s[--len_temp_s] = '\0';

    strcpy(s, temp_s);

    return len_temp_s;
}

int read_data(FILE *f, struct product p[], size_t *n)
{
    fseek(f, 0, SEEK_SET);
    char temp[MAX_STR_LEN];

    *n = 0;

    size_t i = 0;
    int rc;
    while ((rc = line_scan(f, temp, MAX_STR_LEN)) != 0 && rc != MAX_STR_LEN + 1)
    {
        switch (i % 4)
        {
        case 0:
            if (strlen(temp) <= MAX_NAME_LEN)
                strcpy(p[i / 4].name, temp);
            else
                return -1;
            break;
        case 1:
            if (strlen(temp) <= MAX_MFR_LEN)
                strcpy(p[i / 4].mfr, temp);
            else
                return -1;
            break;
        case 2: {
            uint32_t price;
            if ((price = atoi(temp)) != 0)
                p[i / 4].price = price;
            else
                return -1;
            break;
        }
        case 3: {
            uint32_t number;
            if ((number = atoi(temp)) != 0)
                p[i / 4].n = number;
            else
                return -1;
            break;
        }
        }
        ++i;
    }

    if (i % 4 != 0 || rc == MAX_STR_LEN + 1)
        return -1;

    *n = i / 4;
    return ferror(f);
}

int save_data(FILE *f, struct product p[], size_t n)
{
    fseek(f, 0, SEEK_SET);
    for (size_t i = 0; i < n; ++i)
        if (fprintf(f, "%s\n%s\n%" PRIu32 "\n%" PRIu32 "\n", p[i].name, p[i].mfr, p[i].price, p[i].n) < 0)
            return 0;

    return 1;
}

int sort_condition(struct product *p1, struct product *p2)
{
    return (p1->price > p2->price || (p1->price == p2->price && p1->n > p2->n));
}

void insert_data(struct product p[], size_t *n, struct product *new_p)
{
    size_t i = *n;
    for (; i > 0; --i)
        if (sort_condition(&p[i - 1], new_p) == 0)
            p[i] = p[i - 1];
        else
            break;

    p[i] = *new_p;
    ++*n;
}

void sort_data(struct product p[], size_t n)
{
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < i; ++j)
            if (sort_condition(&p[i], &p[j]))
            {
                struct product tmp;
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
}

size_t print_spec_data(struct product p[], size_t n, char *substr)
{
    size_t j = 0;
    for (size_t i = 0; i < n; ++i)
    {
        size_t substr_len = strlen(substr);
        size_t name_len = strlen(p[i].name);
        if (name_len >= substr_len && strcmp(p[i].name + name_len - substr_len, substr) == 0)
        {
            printf("%s\n%s\n%" PRIu32 "\n%" PRIu32 "\n", p[i].name, p[i].mfr, p[i].price, p[i].n);
            ++j;
        }
    }

    return j;
}

long file_size(FILE *f)
{
    fseek(f, 0, SEEK_END);
    return ftell(f);
}
