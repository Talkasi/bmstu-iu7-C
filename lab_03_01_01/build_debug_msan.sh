#!/bin/bash

clang -std=c99 -Wall -Wpedantic -Wextra -Wfloat-equal -Wvla -fsanitize=memory -fPIE -pie \
-Wfloat-conversion -fno-omit-frame-pointer -g main.c matrix.c -o app.exe -lm
