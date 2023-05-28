#!/bin/bash

if [ -z "$2" ] || [ -z "$3" ]; then
    echo "Wrong parameters" >&2
    exit 1
fi

file="$(mktemp)"
command="./app.exe $(cat "$3")"

test_number=$(echo "$3" | grep -o "[0-9]*")
in="func_tests/data/pos_""$test_number""_in.txt"
$command <"$in" >"$file"

state=$(sed 1p "$3" | head -c 2)
if [ "$state" == "st" ] || [ "$state" == "at" ]; then
    if [ -z "$1" ]; then
        echo "Wrong parameters" >&2
        exit 1
    fi

    if func_tests/scripts/comparator.sh "$1" "$2"; then
        rm "$file"
        exit 0
    fi
fi

if [ "$state" == "ft" ]; then
    if func_tests/scripts/comparator.sh "$2" "$file"; then
        rm "$file"
        exit 0
    fi
fi

rm "$file"
exit 1
