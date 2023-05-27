#!/bin/bash

gcc ./func_tests/scripts/tests_converter.c -o tc.out
./tc.out t2b
rm tc.out

./func_tests/scripts/preproc.sh

n_failed=0
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Positive tests
echo "> Positive tests"
for in_stream_file in func_tests/data/pos_*_in_file.bin; do
    test_number=$(echo "$in_stream_file" | grep -o "[0-9]*")
    if [ -z "$test_number" ]; then
        echo "There are no positive tests"
        break
    fi

    args_file="func_tests/data/pos_""$test_number""_args.txt"
    out_stream_file="func_tests/data/pos_""$test_number""_out_file.bin"
    result_stream_file="func_tests/data/pos_""$test_number""_result.bin"
    in_file=$(ls "func_tests/data/pos_""$test_number""_in.txt" 2>/dev/null)
    out_file=$(ls "func_tests/data/pos_""$test_number""_out.txt" 2>/dev/null)

    if func_tests/scripts/pos_case.sh "$out_stream_file" "$result_stream_file" "$args_file" \
        "$in_file" "$out_file" "$in_stream_file"; then
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

rm func_tests/data/pos_*_result.bin 2>/dev/null
rm func_tests/data/neg_*_result.bin 2>/dev/null

if [ "$n_failed" -ne "0" ]; then
    exit 1
else
    exit 0
fi
