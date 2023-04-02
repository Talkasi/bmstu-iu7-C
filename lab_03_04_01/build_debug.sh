#!/bin/bash

gcc -c main.c matrix.c -Werror -Wall -Wpedantic -Wextra -Wfloat-equal -std=c99
gcc main.o matrix.o -o app.exe -lm
