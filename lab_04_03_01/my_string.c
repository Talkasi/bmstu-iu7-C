#include "my_string.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define SEPARATORS " ,;:-.!?"

size_t word_change(char word[]);
int is_present(char word[], size_t last_pos, char c);

size_t line_scan(char *s, size_t s_max_len)
{
    int c;
    size_t i = 0;

    while ((c = getchar()) != '\n' && c != EOF)
        if (i < s_max_len - 1)
            s[i++] = c;
        else
            return 0;

    s[i] = '\0';
    return i;
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
                printf("%zu %20s", nw_len, words[i]);
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

int is_present(char word[], size_t last_pos, char c)
{
    for (size_t i = 0; i < last_pos; ++i)
        if (word[i] == c)
            return 1;

    return 0;
}
