#!/bin/bash

for args_file in "14" "15"; do
    touch "../data/neg_""$args_file""_out_file.txt"
    touch "../data/neg_""$args_file""_in_file.txt"
    touch "../data/neg_""$args_file""_args.txt"
done