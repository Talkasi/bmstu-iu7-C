#include "my_string.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define SEPARATORS " ,;:-.!?"

size_t word_change(char word[]);
int is_present(char word[], size_t max_i, char c);

size_t line_scan(char *s)
{
    char temp_s[MAX_STR_LEN + 1];
    char *temp_p = fgets(temp_s, MAX_STR_LEN + 1, stdin);

    if (temp_p == NULL || temp_s[0] == '\n')
        return 0;

    size_t len_temp_s = strlen(temp_s);
    if (len_temp_s == MAX_STR_LEN && temp_s[len_temp_s - 1] != '\n')
        return MAX_STR_LEN + 1;

    if (temp_s[len_temp_s - 1] == '\n')
        temp_s[--len_temp_s] = '\0';

    strcpy(s, temp_s);

    return len_temp_s;
}

size_t arr_words_fill(char words[][MAX_WORD_LEN], char *s)
{
    char *pword = strtok(s, SEPARATORS);
    size_t n = 0;

    while (pword)
    {
        if (strlen(pword) >= MAX_WORD_LEN)
            return 0;

        strcpy(words[n++], pword);
        pword = strtok(NULL, SEPARATORS);
    }

    return n;
}

size_t line_special_create(char *s, char words[][MAX_WORD_LEN], size_t n_words)
{
    int lw_check = 1;
    s[0] = '\0';

    for (size_t i = n_words - 2; lw_check; --i)
    {
        if (i == 0)
            lw_check = 0;

        if (strcmp(words[i], words[n_words - 1]))
        {
            size_t nw_len = word_change(words[i]);
            if (nw_len > 1)
            {
                words[i][nw_len - 1] = ' ';
                words[i][nw_len] = '\0';

                strcat(s, words[i]);
            }
        }
    }

    size_t s_len = strlen(s);
    if (s_len != 0)
        s[--s_len] = '\0';

    return s_len;
}

size_t word_change(char word[])
{
    size_t j = 0;

    for (size_t i = 0; word[i] != '\0'; ++i)
        if (isalpha(word[i]) && !is_present(word, i, word[i]))
            word[j++] = word[i];

    word[j++] = '\0';
    return j;
}

int is_present(char word[], size_t max_i, char c)
{
    for (size_t i = 0; i < max_i; ++i)
        if (word[i] == c)
            return 1;

    return 0;
}
