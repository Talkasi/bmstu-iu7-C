#include <stdio.h>
#include "my_file.h"

int print_all_students(FILE *f);
int add_student(FILE *f, struct student *new_student);

int main(int argc, char *argv[]) {
	if (argc < 2)
	{
		printf("Error. No file to work with.\n");
		return 0;
	}
	
 	FILE *f;
 	fopen(f, argv[1]);
 	
	fclose(f);
 	
 	return 1;
}

int print_all_students(FILE *f) {
	struct student cur_student;
	while (fread(&cur_student, sizeof(struct student), 1, f) == 1) {
		printf("%5s: %d\n", cur_student.last_name, cur_student.heigh);
	}
	
	return ferror(f);
}

int add_student(FILE *f, struct student *new_student) {
	fwrite(new_student, sizeof(student), 1, f);
	
	return ferror(f);
}
