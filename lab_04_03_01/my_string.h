#ifndef MY_STRING_H
#define MY_STRING_H
#include <stddef.h>

#define MAX_WORD_LEN 17
#define MAX_STR_LEN 257

size_t line_scan(char *s);

size_t line_special_create(char *s, char words[][MAX_WORD_LEN], size_t n_words);
size_t arr_words_fill(char words[][MAX_WORD_LEN], char *s);
size_t word_change(char word[]);

#endif
