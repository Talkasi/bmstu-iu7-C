#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -c -O0 -g3 main.c
gcc main.o -o app.exe -lm
