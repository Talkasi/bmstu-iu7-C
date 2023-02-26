#!/bin/bash

# $1 stores file1
# $2 stores file2
# $3 stores verbose key

# Checks values given to the script for errors
# and through an error to the stderr and 1 exit value if error occurred
error_check() {
  local valid_command="Valid command is: comparator3.sh file_name1 file_name2 [-v]"

  if [ ! -f "$1" ]; then
    echo -e "[!]Error. First parameter is not a file or this file doesn't exist.\n" >&2
    echo "$valid_command" >&2

    exit 1
  elif [ ! -f "$2" ]; then
    echo -e "[!]Error. Second parameter is not a file or this file doesn't exist.\n" >&2
    echo "$valid_command" >&2

    exit 1
  elif [ ! -r "$1" ]; then
    echo -e "[!]Error. There is no permission to open the first file.\n" >&2

    exit 1
  elif [ ! -r "$2" ]; then
    echo -e "[!]Error. There is no permission to open the second file.\n" >&2

    exit 1
  elif [ "$3" != "-v" ] && [ "$3" != "--verbose" ] && [ "$3" != "" ]; then
    echo -e "[!]Error. The key parameter is wrong.\n" >&2
    echo "$valid_command" >&2

    exit 1
  elif [ -n "$4" ]; then
    echo -e "[!]Error. Unexpected parameter after --verbose key.\n" >&2
    echo "$valid_command" >&2

    exit 1
  fi
}

numbers_searcher() {
  file="$(mktemp)"
  were_numbers=0

  DONE=false
  until $DONE; do
    read -r line || DONE=true

    for word in $line; do
      # Check if the word is floating point number or integer or number in scientific notation
      # Regular expression ^[+-]?[0-9]+(\.[0-9]+)?([eE][+-]?[0-9]+)?$
      # is used for that
      if [[ "$word" =~ ^[+-]?[0-9]+(\.[0-9]+)?([eE][+-]?[0-9]+)?$ ]]; then
        were_numbers=1
        echo "$word" >>"$file"
      fi
    done
  done <"$1"

  if [ $were_numbers -eq 0 ]; then
    echo "[!]Error. There are no suitable floating point numbers in file '$1'" >&2

    exit 1
  fi
}

error_check "$1" "$2" "$3" "$4"

file=""

numbers_searcher "$1"
file1="$file"
numbers_searcher "$2"
file2="$file"

if cmp -s "$file1" "$file2"; then
  if [ "$3" == "-v" ] || [ "$3" == "--verbose" ]; then
    echo "[+]Corresponding numbers in given files are equal."
  fi
  rm "$file1" "$file2"

  exit 0
else
  if [ "$3" == "-v" ] || [ "$3" == "--verbose" ]; then
    echo "[-]Corresponding numbers in given files are NOT equal."
  fi
  rm "$file1" "$file2"

  exit 1
fi
