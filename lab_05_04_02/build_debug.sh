#!/bin/bash

gcc -c main.c my_product.c -Werror -Wall -Wpedantic -Wextra -Wfloat-equal -std=c99 -g3
gcc main.o my_product.o -o app.exe -lm
