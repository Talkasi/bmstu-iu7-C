#!/bin/bash

clang -std=c99 -Wall -Wpedantic -Wextra -Wfloat-equal -Wvla -Wfloat-conversion -fsanitize=address -fno-omit-frame-pointer -g ./*.c -o app.exe -lm
