#!/bin/bash

if [ -z "$1" ] || [ -z "$2" ] ; then
  echo "Wrong parameters" >&2
  exit 1
fi

file="$(mktemp)"
../../app.exe < "$1" > "$file"

if [ -z "$(cat "$2")" ]; then
  if [ "$(cat "$file")" == "Enter number to work with: " ]; then
    exit 0
  else
    exit 1
  fi
fi

if ./comparator.sh "$file" "$2"; then
  rm "$file"
  exit 0
else
  rm "$file"
  exit 1
fi
