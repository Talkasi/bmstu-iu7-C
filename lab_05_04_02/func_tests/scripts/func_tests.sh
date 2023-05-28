#!/bin/bash

./func_tests/scripts/preproc.sh

n_failed=0
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Positive tests
echo "> Positive tests"
for args_file in func_tests/data/pos_*_args.txt; do
    test_number=$(echo "$args_file" | grep -o "[0-9]*")
    if [ -z "$test_number" ]; then
        echo "There are no positive tests"
        break
    fi

    state=$(sed 1p "$args_file" | head -c 2)

    if [ "$state" == "st" ]; then
        out_stream_file="func_tests/data/pos_""$test_number""_out_file.txt"
        in_stream_file="func_tests/data/pos_""$test_number""_result.txt"
    fi

    if [ "$state" == "ft" ]; then
        out_stream_file="func_tests/data/pos_""$test_number""_out.txt"
        in_stream_file="func_tests/data/pos_""$test_number""_in.txt"
    fi

    if [ "$state" == "at" ]; then
        out_stream_file="func_tests/data/pos_""$test_number""_out_file.txt"
        in_stream_file="func_tests/data/pos_""$test_number""_in_file.txt"
    fi

    if func_tests/scripts/pos_case.sh "$in_stream_file" "$out_stream_file" "$args_file"; then
        echo -e "Test ""$test_number"": ${GREEN}PASSED${NC}"
    else
        n_failed=$((n_failed + 1))
        echo -e "Test ""$test_number"": ${RED}FAILED${NC}"
    fi
done

# Negative tests
echo "> Negative tests"
for args_file in func_tests/data/neg_*_args.txt; do
    test_number=$(echo "$args_file" | grep -o "[0-9]*")
    if [ -z "$test_number" ]; then
        echo "There are no negative tests"
        break
    fi

    in_file=$(ls "func_tests/data/neg_""$test_number""_in.txt" 2>/dev/null)

    if func_tests/scripts/neg_case.sh "$in_file" "$args_file"; then
        echo -e "Test ""$test_number"": ${GREEN}PASSED${NC}"
    else
        n_failed=$((n_failed + 1))
        echo -e "Test ""$test_number"": ${RED}FAILED${NC}"
    fi
done

rm func_tests/data/pos_*_result.txt 2>/dev/null
rm func_tests/data/neg_*_result.txt 2>/dev/null

if [ "$n_failed" -ne "0" ]; then
    exit 1
else
    exit 0
fi
