#!/bin/bash

./test.sh
echo -e "\n'gcov':\n"
gcov main.c
