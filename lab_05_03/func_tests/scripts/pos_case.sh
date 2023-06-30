#!/bin/bash
# Parameters:
# 1 - "$result_stream_file"
# 2 - "$out_stream_file"
# 3 - "$args_file"
if [ -z "$2" ] || [ -z "$3" ]; then
    echo "Wrong parameters" >&2
    exit 1
fi

file="$(mktemp)"
command="./app.exe $(cat "$3")"

state=$(sed 1p "$3" | head -c 1)
$command >"$file"

if [ "$state" == "p" ]; then
    if func_tests/scripts/comparator.sh "$2" "$file"; then
        rm "$file"
        exit 0
    fi
fi

if [ "$state" == "s" ]; then
    if [ -z "$1" ]; then
        echo "Wrong parameters" >&2
        exit 1
    fi

    if func_tests/scripts/comparator.sh "$1" "$2"; then
        rm "$file"
        exit 0
    fi
fi

rm "$file"
exit 1
