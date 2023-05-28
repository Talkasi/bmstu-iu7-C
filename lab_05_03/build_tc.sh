#!/bin/bash
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion \
    -Wvla -O3 ./func_tests/scripts/tests_converter.c -o tc.out
