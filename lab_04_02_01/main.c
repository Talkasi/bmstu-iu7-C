#include "my_string.h"
#include <stdio.h>

#define INPUT_LINE_ERROR 1
#define NO_WORDS_ERROR 2

#define MAX_STR_LEN 257

int main(void)
{
    char s[MAX_STR_LEN];

    printf("Enter a line: \n");
    if (line_scan(s, MAX_STR_LEN) == 0)
        return INPUT_LINE_ERROR;

    char words[MAX_STR_LEN / 2][MAX_WORD_LEN];
    size_t n_words = arr_uwords_fill(words, s);

    if (n_words == 0)
        return NO_WORDS_ERROR;

    buble_sort(words, n_words);

    printf("Result: ");
    str_arr_print(words, n_words);

    return 0;
}
