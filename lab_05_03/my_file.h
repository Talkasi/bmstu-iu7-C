#ifndef MY_FILE_H
#define MY_FILE_H
#include <inttypes.h>
#include <stdio.h>

typedef int32_t my_type;

int rand_fill(FILE *f, size_t n_numbers);
int print_nums(FILE *f);
size_t file_size(FILE *f);
int get_number_by_pos(FILE *f, my_type *num, size_t pos);
int put_number_by_pos(FILE *f, my_type num, size_t pos);
int bubble_sort(FILE *f);

#endif
