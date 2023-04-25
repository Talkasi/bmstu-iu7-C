#ifndef MY_STRING_H
#define MY_STRING_H
#include <stddef.h>

char *my_strpbrk(char *s, char *accept);

size_t my_strspn(char *s, char *accept);
size_t my_strcspn(char *s, char *reject);

char *my_strchr(char *s, int c);
char *my_strrchr(char *s, int c);

#endif
