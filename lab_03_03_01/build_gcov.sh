#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -c -O0 -g3 --coverage ./*.c
gcc ./*.o -o app.exe --coverage -lm
