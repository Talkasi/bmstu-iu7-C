#!/bin/bash

gcc -c ./*.c -Werror -Wall -Wpedantic -Wextra -Wfloat-equal -std=c99 -g3
gcc ./*.o -o app.exe -lm
