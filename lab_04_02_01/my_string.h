#ifndef MY_STRING_H
#define MY_STRING_H
#include <stddef.h>

#define MAX_WORD_LEN 16

size_t line_scan(char *s, size_t s_max_len);
void str_arr_print(char words[][MAX_WORD_LEN], size_t words_len);

size_t arr_uwords_fill(char words[][MAX_WORD_LEN], char *s);
void str_sort(char words[][MAX_WORD_LEN], size_t words_len);

#endif
