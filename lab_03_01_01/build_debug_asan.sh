#!/bin/bash

clang -std=c99 -Wall -Wpedantic -Wextra -Wfloat-equal -Wvla -Wfloat-conversion -fsanitize=address \
-fno-omit-frame-pointer -g main.c matrix.c -o app.exe -lm
