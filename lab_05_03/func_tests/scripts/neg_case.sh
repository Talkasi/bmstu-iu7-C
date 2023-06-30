#!/bin/bash
# Parameters:
# 1 - "$in_file"
# 2 - "$args_file"
if [ -z "$2" ] ; then
  echo "Wrong parameters" >&2
  exit 1
fi

command="./app.exe $(cat "$2")"

if [ -z "$1" ]; then
    $command > /dev/null
else
    $command < "$1" > /dev/null
fi

rc=$(echo -ne $?)
if [ "$rc" -eq 0 ]; then
  exit 1
else
  exit 0
fi
