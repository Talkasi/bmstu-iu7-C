#ifndef MY_FILE_H
#define MY_FILE_H
#include <stdio.h>
#include <inttypes.h>

typedef int64_t my_type;

int rand_fill(FILE *f, size_t n_numbers);
int print(FILE *f);

size_t file_size(FILE *f);
my_type get_number_by_pos(FILE *f, size_t pos);
void put_number_by_pos(FILE *f, my_type number, size_t pos);
void bubble_sort(FILE *f);

#endif
