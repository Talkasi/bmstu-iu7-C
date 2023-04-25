#ifndef MY_STRING_H
#define MY_STRING_H
#include <stddef.h>

char *my_strpbrk(const char *s, const char *accept);

size_t my_strspn(const char *s, const char *accept);
size_t my_strcspn(const char *s, const char *reject);

char *my_strchr(const char *s, int c);
char *my_strrchr(const char *s, int c);

#endif
