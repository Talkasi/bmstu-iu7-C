#ifndef MY_FILE_H
#define MY_FILE_H
#include <inttypes.h>
#include <stdio.h>

#define MAX_NAME_LEN 5
#define FILE_READ_ERROR -1

#pragma pack(push, 1)
struct student
{
    char last_name[MAX_NAME_LEN + 1];
    uint32_t height;
};
#pragma pack(pop)

long file_size(FILE *f);
int add_student(FILE *f, struct student *new_student);
int print_all_students(FILE *f);
int avrg_height(FILE *f, double *average);
int delete_students_by_cond(FILE *f, double average);

#endif
