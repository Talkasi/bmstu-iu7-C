#ifndef MY_PRODUCT_H
#define MY_PRODUCT_H
#include <inttypes.h>
#include <stdio.h>

#define MAX_STR_LEN 256
#define MAX_NAME_LEN 30
#define MAX_MFR_LEN 15

struct product
{
    char name[MAX_NAME_LEN];
    char mfr[MAX_MFR_LEN];
    uint32_t price;
    uint32_t n;
};

long file_size(FILE *f);
int read_data(FILE *f, struct product p[], size_t *n);
int save_data(FILE *f, struct product p[], size_t n);
void sort_data(struct product p[], size_t n);
size_t line_scan(FILE *f, char *s, size_t max_s_len);
void insert_data(struct product p[], size_t *n, struct product *new_p);
void print_data(struct product p[], size_t n);
size_t print_spec_data(struct product p[], size_t n, char *substr);

#endif
