#!/bin/bash

if [ -z "$1" ] || [ -z "$2" ] || [ -z "$3" ]; then
  echo "Wrong parameters" >&2
  exit 1
fi

file="$(mktemp)"
command="./app.exe $(cat "$3")"
$command < "$1" > "$file"

if func_tests/scripts/comparator.sh "$file" "$2"; then
  rm "$file"
  exit 0
else
  rm "$file"
  exit 1
fi
