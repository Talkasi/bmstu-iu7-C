#ifndef MY_FILE_H
#define MY_FILE_H
#include <stdio.h>

int find_extremums_pos(FILE *f, size_t *min_pos, size_t *max_pos);
int average(FILE *f, double *avrg, size_t start_pos, size_t end_pos);

#endif
