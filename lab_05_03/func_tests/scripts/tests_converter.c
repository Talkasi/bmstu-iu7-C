#include <dirent.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TESTS_DIR "./func_tests/data"
#define BIN "file.bin"
#define TXT "file.txt"

#define MAX_DIR_LEN 256
#define MAX_STR_LEN 100

#define B2T 0
#define T2B 1

typedef int32_t my_type;

void search_dir(char *path, int state);
int txt_to_bin(char in_path[MAX_DIR_LEN]);
int bin_to_txt(char in_path[MAX_DIR_LEN]);
size_t line_scan(FILE *f, char *s);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./app.exe b2t\n./app.exe t2b\n");
        return 1;
    }

    if (strcmp(argv[1], "t2b") == 0)
        search_dir(TESTS_DIR, T2B);
    else if (strcmp(argv[1], "b2t") == 0)
        search_dir(TESTS_DIR, B2T);
    else
    {
        printf("Usage: ./app.exe b2t\n./app.exe t2b\n");
        return 1;
    }

    return 0;
}

void search_dir(char *path, int state)
{
    DIR *dp = opendir(path);
    if (!dp)
    {
        perror(path);
        return;
    }

    struct dirent *ep;
    while ((ep = readdir(dp)))
        if (strncmp(ep->d_name, ".", 1) != 0)
        {
            size_t dir_len = strlen(ep->d_name);
            char cur_path[MAX_DIR_LEN] = "";
            strcat(cur_path, TESTS_DIR);
            strcat(cur_path, "/");
            if (state == T2B && dir_len > strlen(TXT) && strcmp(ep->d_name + dir_len - strlen(TXT), TXT) == 0)
                txt_to_bin(strcat(cur_path, ep->d_name));

            if (state == B2T && dir_len > strlen(BIN) && strcmp(ep->d_name + dir_len - strlen(BIN), BIN) == 0)
                bin_to_txt(strcat(cur_path, ep->d_name));
        }

    closedir(dp);
}

int txt_to_bin(char in_path[MAX_DIR_LEN])
{
    FILE *f_in = fopen(in_path, "r");
    if (f_in == NULL)
        return -1;

    char out_path[MAX_DIR_LEN] = "";
    strncpy(out_path, in_path, strlen(in_path) - strlen(TXT));
    strcat(out_path, BIN);

    FILE *f_out = fopen(out_path, "wb");
    if (f_out == NULL)
    {
        fclose(f_in);
        return -1;
    }
    rewind(f_in);

    char num[MAX_STR_LEN];
    size_t rc;
    while ((rc = line_scan(f_in, num)) != 0 && rc != MAX_STR_LEN + 1)
    {
        my_type temp = (my_type)atoi(num);
        fwrite(&temp, sizeof(my_type), 1, f_out);
    }

    fclose(f_in);
    fclose(f_out);
    return 0;
}

int bin_to_txt(char in_path[MAX_DIR_LEN])
{
    FILE *f_in = fopen(in_path, "rb");
    if (f_in == NULL)
        return -1;

    char out_path[MAX_DIR_LEN] = "";
    strncpy(out_path, in_path, strlen(in_path) - strlen(BIN));
    strcat(out_path, TXT);

    FILE *f_out = fopen(out_path, "w");
    if (f_out == NULL)
    {
        fclose(f_in);
        return -1;
    }

    rewind(f_in);
    my_type num;
    while (fread(&num, sizeof(my_type), 1, f_in) == 1)
        fprintf(f_out, "%" PRId32 "\n", num);

    fclose(f_in);
    fclose(f_out);
    return 0;
}

size_t line_scan(FILE *f, char *s)
{
    char temp_s[MAX_STR_LEN + 1];
    if (fgets(temp_s, MAX_STR_LEN + 1, f) == NULL)
        return 0;

    size_t len_temp_s = strlen(temp_s);
    if ((len_temp_s == MAX_STR_LEN && temp_s[len_temp_s - 1] != '\n'))
        return MAX_STR_LEN + 1;

    if (temp_s[len_temp_s - 1] == '\n')
        temp_s[--len_temp_s] = '\0';

    strcpy(s, temp_s);
    return len_temp_s;
}
