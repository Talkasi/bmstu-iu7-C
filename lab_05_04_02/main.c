#include "my_product.h"
#include <stdio.h>
#include <string.h>

#define WRONG_PARAMETERS 53
#define FILE_OPEN_ERROR 3
#define EMPTY_FILE_ERROR 4
#define READING_ERROR 5
#define WRITING_ERROR 6
#define NO_SPEC_DATA 7
#define WRONG_INPUT_PARAMETER 8

int sort_text(char *dst_path, char *src_path);
int name_text(char *f_path, char *substr);
int add_text(char *f_path);

int scan_data(struct product *new_p);

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage:\nprogram st SRC_FILE DST_FILE\nprogram ft FILE SUBSTR\nprogram at FILE\n");
        return WRONG_PARAMETERS;
    }

    if (strcmp(argv[1], "st") == 0)
    {
        if (argc != 4)
        {
            printf("Usage: program st SRC_FILE DST_FILE\n");
            return WRONG_PARAMETERS;
        }

        int rc = sort_text(argv[3], argv[2]);
        if (rc)
        {
            printf("Error while sorting\n");
            return rc;
        }
    }
    else if (strcmp(argv[1], "ft") == 0)
    {
        if (argc != 4)
        {
            printf("Usage: program ft FILE SUBSTR\n");
            return WRONG_PARAMETERS;
        }

        int rc = name_text(argv[2], argv[3]);
        if (rc)
        {
            printf("Error while printing special products\n");
            return rc;
        }
    }
    else if (strcmp(argv[1], "at") == 0)
    {
        if (argc != 3)
        {
            printf("Usage: program at FILE\n");
            return WRONG_PARAMETERS;
        }

        int rc = add_text(argv[2]);
        if (rc)
        {
            printf("Error while adding a product\n");
            return rc;
        }
    }
    else
    {
        printf("Usage:\nprogram st SRC_FILE DST_FILE\nprogram ft FILE SUBSTR\nprogram at FILE\n");
        return WRONG_PARAMETERS;
    }

    return 0;
}

int sort_text(char *dst_path, char *src_path)
{
    FILE *src_f = fopen(src_path, "r");
    if (src_f == NULL)
        return FILE_OPEN_ERROR;

    if (file_size(src_f) == 0)
        return EMPTY_FILE_ERROR;

    FILE *dst_f = fopen(dst_path, "w");
    if (dst_f == NULL)
        return FILE_OPEN_ERROR;

    struct product p[BUFSIZ];
    size_t n;

    if (read_data(src_f, p, &n))
        return READING_ERROR;

    sort_data(p, n);

    if (save_data(dst_f, p, n) == 0)
        return WRITING_ERROR;

    fclose(src_f);
    fclose(dst_f);
    return 0;
}

int name_text(char *f_path, char *substr)
{
    FILE *f = fopen(f_path, "r");
    if (f == NULL)
        return FILE_OPEN_ERROR;

    if (file_size(f) == 0)
        return EMPTY_FILE_ERROR;

    struct product p[BUFSIZ];
    size_t n;

    if (read_data(f, p, &n))
        return READING_ERROR;

    if (print_spec_data(p, n, substr) == 0)
        return NO_SPEC_DATA;

    fclose(f);
    return 0;
}

int add_text(char *f_path)
{
    FILE *f = fopen(f_path, "r+");
    if (f == NULL)
        return FILE_OPEN_ERROR;

    if (file_size(f) == 0)
        return EMPTY_FILE_ERROR;

    struct product p[BUFSIZ];
    size_t n;

    struct product new_p;

    int rc;
    if ((rc = scan_data(&new_p)))
        return rc;

    if (read_data(f, p, &n))
        return READING_ERROR;

    insert_data(p, &n, &new_p);

    if (save_data(f, p, n) == 0)
        return WRITING_ERROR;

    fclose(f);
    return 0;
}

int scan_data(struct product *new_p)
{
    size_t rc;
    printf("Enter name of a product to add: ");
    if ((rc = line_scan(stdin, new_p->name, MAX_NAME_LEN)) == 0 || rc == MAX_NAME_LEN + 1)
        return WRONG_INPUT_PARAMETER;

    printf("Enter manufacture of the product: ");
    if ((rc = line_scan(stdin, new_p->mfr, MAX_MFR_LEN)) == 0 || rc == MAX_MFR_LEN + 1)
        return WRONG_INPUT_PARAMETER;

    printf("Enter price of the product: ");
    if (scanf("%" SCNu32, &new_p->price) != 1 || new_p->price == 0)
        return WRONG_INPUT_PARAMETER;

    printf("Enter amount of such products: ");
    if (scanf("%" SCNu32, &new_p->n) != 1)
        return WRONG_INPUT_PARAMETER;

    return 0;
}
