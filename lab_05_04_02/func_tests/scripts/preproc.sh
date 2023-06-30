#!/bin/bash

for preproc_file in func_tests/data/pos_*_preproc.txt; do
    test_number=$(echo "$preproc_file" | grep -o "[0-9]*")
    if [ -z "$test_number" ]; then
        echo "There are no positive tests"
        break
    fi

    cat "$preproc_file" > "func_tests/data/pos_""$test_number""_in_file.txt"
done
