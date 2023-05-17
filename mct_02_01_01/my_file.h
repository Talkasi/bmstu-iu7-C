#ifndef MY_FILE_H
#define MY_FILE_H
#include <stdio.h>

#define MAX_NAME_LEN 5

struct student {
	char last_name[MAX_NAME_LEN];
	int heigh;
}

int average(FILE *f, int *average);
int delete_students_by_cond(FILE *f, int average);

#endif
