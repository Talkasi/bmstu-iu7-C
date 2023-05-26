#!/bin/bash
# Parameters:
# 1 - "$out_stream_file"
# 2 - "$result_stream_file"
# 3 - "$args_file"
# 4 - "$in_file"
# 5 - "$out_file"
# 6 - "$in_stream_file"
if [ -z "$1" ] || [ -z "$2" ] || [ -z "$3" ]; then
    echo "Wrong parameters" >&2
    exit 1
fi

file="$(mktemp)"
command="./app.exe $(cat "$3")"

if [ -z "$4" ]; then
    $command >"$file"
else
    $command <"$4" >"$file"
fi

result_stream_file=$(ls "$2" 2> /dev/null)
if [ -z "$result_stream_file" ]; then
    result_stream_file="$6"
fi

if [ -n "$5" ] && func_tests/scripts/comparator.sh "$5" "$file"; then
    rm "$file"
    exit 0
fi

if [ -n "$2" ] && func_tests/scripts/comparator.sh "$1" "$result_stream_file"; then
    rm "$file"
    exit 0
fi

rm "$file"
exit 1
