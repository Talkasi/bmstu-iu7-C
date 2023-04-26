#include "my_string.h"
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 256

int main(void)
{
    char s[MAX_STR_LEN];
    if (fgets(s, MAX_STR_LEN, stdin) == NULL)
        return 1;

    size_t s_len = strlen(s);
    if (s[s_len - 1] == '\n')
        s[s_len - 1] = '\0';

    char words[MAX_STR_LEN / 2][MAX_WORD_LEN];
    size_t n_words = arr_words_fill(words, s);

    if (n_words == 0)
        return 1;

    char new_s[MAX_STR_LEN] = "";
    line_special_create(new_s, words, n_words);

    printf("Result: %s\n", new_s);

    return 0;
}
