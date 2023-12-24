#!/bin/bash

if [ $# -ne 2 ]; then
    exit 1
fi

program_out=$1
test_out=$2

if cmp "$program_out" "$test_out"; then
    exit 0
fi

exit 1