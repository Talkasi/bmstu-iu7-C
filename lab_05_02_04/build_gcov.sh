#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -c -O0 -g3 --coverage main.c my_file.c
gcc main.o my_file.o -o app.exe --coverage -lm
