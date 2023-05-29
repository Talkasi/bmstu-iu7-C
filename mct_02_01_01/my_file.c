#include "my_file.h"

int print_all_students(FILE *f)
{
    fseek(f, 0, SEEK_SET);
    struct student cur_student;

    do
    {
        if (fread(&cur_student, sizeof(struct student), 1, f) != 1)
            return FILE_READ_ERROR;
        printf("%s: %d\n", cur_student.last_name, cur_student.height);
    } while (!feof(f));

    return 0;
}

int avrg_height(FILE *f, double *average)
{
    fseek(f, 0, SEEK_SET);
    struct student cur_student;
    *average = 0;
    size_t i = 0;
    while (fread(&cur_student, sizeof(struct student), 1, f) == 1)
    {
        *average += cur_student.height;
        ++i;
    }

    *average /= (double)i;
    return feof(f) ? 0 : -1;
}

int delete_students_by_cond(FILE *f, double average)
{
    fseek(f, 0, SEEK_SET);
    struct student cur_student;
    size_t n = 0;
    long cur_pos;

    while (fread(&cur_student, sizeof(struct student), 1, f) == 1)
        if (cur_student.height >= (uint32_t)average)
        {
            cur_pos = ftell(f);
            fseek(f, n * sizeof(struct student), SEEK_SET);
            fwrite(&cur_student, sizeof(struct student), 1, f);
            fseek(f, cur_pos, SEEK_SET);
            ++n;
        }

    return feof(f) ? 0 : -1;
}

long file_size(FILE *f)
{
    long cur_pos = ftell(f);
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, cur_pos, SEEK_SET);
    return fsize;
}

int add_student(FILE *f, struct student *new_student)
{
    fseek(f, 0, SEEK_END);
    fwrite(new_student, sizeof(struct student), 1, f);
    return ferror(f);
}
