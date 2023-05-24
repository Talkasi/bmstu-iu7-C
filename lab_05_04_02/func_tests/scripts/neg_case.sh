#!/bin/bash

if [ -z "$1" ] || [ -z "$2" ] ; then
  echo "Wrong parameters" >&2
  exit 1
fi

command="./app.exe $(cat "$2")"

if $command < "$1" > /dev/null; then
  exit 1
else
  exit 0
fi
