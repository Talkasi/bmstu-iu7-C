#!/bin/bash

for args_file in "05" "06" "07" "08" "09" "10" "11" "12" "13"; do
    touch "../data/neg_""$args_file""_in.txt"
    touch "../data/neg_""$args_file""_in_file.txt"
    touch "../data/neg_""$args_file""_args.txt"
done