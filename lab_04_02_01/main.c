#include "my_string.h"
#include <stdio.h>

#define MAX_STR_LEN 256

int main(void)
{
    char s[MAX_STR_LEN];
    if (line_scan(s, MAX_STR_LEN) == 0)
        return 1;

    char words[MAX_STR_LEN][MAX_WORD_LEN];
    size_t n_words = arr_uwords_fill(words, s);

    if (n_words == 0)
        return 1;

    str_sort(words, n_words);

    printf("Result: ");
    str_arr_print(words, n_words);

    return 0;
}
