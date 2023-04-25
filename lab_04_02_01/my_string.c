#include "my_string.h"
#include <stdio.h>
#include <string.h>

int is_unique(char words[][MAX_WORD_LEN], size_t words_len, char *word);
int is_separator(char c);
char *separators = " ,;:-.!?";

size_t line_scan(char *s, size_t s_max_len)
{
    int c;
    size_t i = 0;

    while ((c = getchar()) != '\n' && c != EOF)
        if (i < s_max_len - 1)
            s[i++] = c;

    s[i] = '\0';
    return i;
}

size_t arr_uwords_fill(char words[][MAX_WORD_LEN], char *s)
{
    size_t in_word = 0;
    size_t n_words = 0;

    char word[MAX_WORD_LEN];
    size_t j = 0;

    for (size_t i = 0; s[i] != '\0'; ++i)
    {
        if (is_separator(s[i]))
        {
            if (in_word)
            {
                in_word = 0;
                word[j++] = '\0';

                if (n_words == 0 || is_unique(words, n_words, word))
                {
                    strncpy(words[n_words], word, j);
                    ++n_words;
                }

                j = 0;
            }
        }
        else
        {
            if (!in_word)
                in_word = 1;

            if (j + 1 < MAX_WORD_LEN)
                word[j++] = s[i];
            else
                return 0;
        }
    }

    if (in_word)
    {
        word[j++] = '\0';
        if (is_unique(words, n_words, word))
            strncpy(words[n_words++], word, j);
    }

    return n_words;
}

int is_unique(char words[][MAX_WORD_LEN], size_t words_len, char *word)
{
    for (size_t i = 0; i < words_len; ++i)
        if (strcmp(words[i], word) == 0)
            return 0;

    return 1;
}

int is_separator(char c)
{
    for (size_t i = 0; separators[i] != '\0'; ++i)
        if (c == separators[i])
            return 1;

    return 0;
}

void str_arr_print(char words[][MAX_WORD_LEN], size_t words_len)
{
    for (size_t i = 0; i < words_len; ++i)
    {
        for (size_t j = 0; words[i][j] != '\0'; ++j)
            putchar(words[i][j]);

        putchar(' ');
    }
}

void str_sort(char words[][MAX_WORD_LEN], size_t words_len)
{
    for (size_t i = 0; i < words_len - 1; ++i)
        for (size_t j = i + 1; j < words_len; ++j)
            if (strcmp(words[i], words[j]) > 0)
            {
                char temp[MAX_WORD_LEN];

                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
}
