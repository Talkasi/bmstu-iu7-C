#ifndef MY_FILE_H
#define MY_FILE_H
#include <stdio.h>

#define READING_ERROR -1
#define WRONG_BOUNDS_ERROR -2

int extremums_pos(FILE *f, size_t *min_pos, size_t *max_pos);
int bounds_correct(size_t *l_pos, size_t *r_pos);
int avrg(FILE *f, double *avrg, size_t start_pos, size_t end_pos);

#endif
