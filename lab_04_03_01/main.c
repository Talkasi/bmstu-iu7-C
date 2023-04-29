#include "my_string.h"
#include <stdio.h>

int main(void)
{
    char s[MAX_STR_LEN];

    printf("Enter a line: \n");
    if (line_scan(s) == 0)
        return 1;

    char words[MAX_STR_LEN / 2][MAX_WORD_LEN];
    size_t n_words = arr_words_fill(words, s);

    if (n_words <= 1)
        return 1;

    char new_s[MAX_STR_LEN];
    line_special_create(new_s, words, n_words);

    printf("Result: %s\n", new_s);

    return 0;
}
