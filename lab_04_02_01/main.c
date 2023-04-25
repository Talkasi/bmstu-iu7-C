#include "my_string.h"
#include <stdio.h>

#define MAX_STR_LEN 1024

int main(void)
{
    char s[MAX_STR_LEN];
    if (fgets(s, MAX_STR_LEN, stdin) == NULL)
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
