#!/bin/bash

gcc -c main.c my_file.c -Werror -Wall -Wpedantic -Wextra -Wfloat-equal -std=c99
gcc main.o my_file.o -o app.exe -lm
