#!/bin/bash

clang -std=c99 -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -fsanitize=undefined -fno-omit-frame-pointer -g main.c my_file.c -o app.exe -lm
