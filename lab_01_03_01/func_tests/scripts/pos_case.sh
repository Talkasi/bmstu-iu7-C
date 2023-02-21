#!/bin/bash

if [ -z "$1" ] || [ -z "$2" ] ; then
  echo "Wrong parameters" >&2
  exit 1
fi

file="$(mktemp)"
../../app.exe < "$1" > "$file"

if ./comparator.sh "$file" "$2"; then
  rm "$file"
  exit 0
else
  rm "$file"
  exit 1
fi
