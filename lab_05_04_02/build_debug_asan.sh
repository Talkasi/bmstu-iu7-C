#!/bin/bash

clang -std=c99 -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -fsanitize=address -fno-omit-frame-pointer -g main.c my_product.c -o app.exe -lm
