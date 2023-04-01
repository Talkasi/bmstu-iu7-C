#!/bin/bash

clang -std=c99 -Wall -Wvla -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -fsanitize=undefined -fno-omit-frame-pointer -g ./*.c -o app.exe -lm
