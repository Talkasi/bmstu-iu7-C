#include "my_string.h"
#include <stdio.h>

#define EMPTY_LINE_ERROR 1
#define TOO_LONG_LINE_ERROR 2
#define EMPTY_RESULT_ERROR 3

int main(void)
{
    char s[MAX_STR_LEN];

    printf("Enter a line: \n");
    size_t rc = line_scan(s);
    if (rc == 0)
        return EMPTY_LINE_ERROR;

    if (rc == MAX_STR_LEN + 1)
        return TOO_LONG_LINE_ERROR;

    char words[MAX_STR_LEN / 2][MAX_WORD_LEN];
    size_t n_words = arr_words_fill(words, s);

    if (n_words <= 1)
        return EMPTY_RESULT_ERROR;

    char new_s[MAX_STR_LEN];
    size_t new_s_len = line_special_create(new_s, words, n_words);

    if (!new_s_len)
        return EMPTY_RESULT_ERROR;

    printf("Result: %s\n", new_s);

    return 0;
}
