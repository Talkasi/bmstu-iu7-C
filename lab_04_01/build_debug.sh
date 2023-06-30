#!/bin/bash

gcc -c main.c my_string.c -Werror -Wall -Wpedantic -Wextra -Wfloat-equal -g3 -std=c99
gcc main.o my_string.o -o app.exe -lm
