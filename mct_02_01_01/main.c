#include "my_file.h"
#include <stdio.h>
#include <string.h>

#define WRONG_PARAMETERS 53
#define OPEN_FILE_ERROR 1
#define FILE_SIZE_ERROR 2
#define WRONG_STUDENT_DATA 3

size_t line_scan(char *s);
int read_student(struct student *new_student);

int main(int argc, char *argv[])
{
    if (argc != 3)
        return WRONG_PARAMETERS;

    if (strcmp(argv[1], "p") == 0)
    {
        FILE *f = fopen(argv[2], "rb");
        if (f == NULL)
            return OPEN_FILE_ERROR;

        long fsize = file_size(f);
        if (fsize == 0 || fsize % sizeof(struct student) != 0)
        {
            fclose(f);
            return FILE_SIZE_ERROR;
        }

        print_all_students(f);
        fclose(f);
    }
    else if (strcmp(argv[1], "a") == 0)
    {
        FILE *f = fopen(argv[2], "rb+");
        if (f == NULL)
            return OPEN_FILE_ERROR;

        long fsize = file_size(f);
        if (fsize % sizeof(struct student) != 0)
        {
            fclose(f);
            return FILE_SIZE_ERROR;
        }

        struct student new_student = { "", 0 };
        int rc = read_student(&new_student);
        if (rc)
        {
            fclose(f);
            return rc;
        }

        add_student(f, &new_student);
        fclose(f);
    }
    else if (strcmp(argv[1], "d") == 0)
    {
        FILE *f = fopen(argv[2], "rb+");
        if (f == NULL)
            return OPEN_FILE_ERROR;

        long fsize = file_size(f);
        if (fsize == 0 || fsize % sizeof(struct student) != 0)
        {
            fclose(f);
            return FILE_SIZE_ERROR;
        }

        double avrg;
        avrg_height(f, &avrg);
        delete_students_by_cond(f, avrg);
        fclose(f);
    }
    else
        return WRONG_PARAMETERS;

    return 0;
}

size_t line_scan(char *s)
{
    char temp_s[MAX_NAME_LEN + 1];
    if (fgets(temp_s, MAX_NAME_LEN + 1, stdin) == NULL)
        return 0;

    size_t len_temp_s = strlen(temp_s);
    if ((len_temp_s == MAX_NAME_LEN + 1 && temp_s[len_temp_s - 1] != '\n'))
        return MAX_NAME_LEN + 1;

    if (temp_s[len_temp_s - 1] == '\n')
        temp_s[--len_temp_s] = '\0';

    strcpy(s, temp_s);
    return len_temp_s;
}

int read_student(struct student *new_student)
{
    int rc;
    if ((rc = line_scan(new_student->last_name)) == 0 || rc == MAX_NAME_LEN + 1)
        return WRONG_STUDENT_DATA;

    if (scanf("%" SCNu32, &new_student->height) != 1 || new_student->height == 0)
        return WRONG_STUDENT_DATA;

    return 0;
}
