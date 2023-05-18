#ifndef MY_FILE_H
#define MY_FILE_H
#include <stdio.h>

void rand_fill(FILE *f, size_t n_numbers);
void print(FILE *f);

size_t file_size(FILE *f);
int get_number_by_pos(FILE *f, size_t pos);
void put_number_by_pos(FILE *f, int number, size_t pos);
void bubble_sort(FILE *f);

#endif
