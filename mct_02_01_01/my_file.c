#include "my_file.h"

int average(FILE *f, int *average) {
	struct student cur_student;
	*average = 0;
	size_t i = 0;
	while (fread(&cur_student, sizeof(struct student), 1, f) == 1) {
		*average += cur_student.heigh;
		++i;
	}
	*average /= (int)i;
	return ferror(f);
}

int delete_students_by_cond(FILE *f, int average) {
	struct student cur_student;
	size_t i = 0;
	long cur_pos;
	while (fread(&cur_student, sizeof(struct student), 1, f) == 1) {
		if (cur_student.heigh >= average) {
			cur_pos = ftell(f);
			fseek(f, -i * sizeof(student), SEEK_CUR);
			fwrite(cur_student, sizeof(student), 1, f);
			fseek(f, cur_pos, SEEK_SET);
		}
		else
			++i;
	}
	
	return ferror(f);
}
