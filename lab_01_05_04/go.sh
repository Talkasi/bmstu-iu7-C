#!/bin/bash

./clean.sh
echo ">>> Check scripts start"
./check_scripts.sh
echo -e ">>> Check scripts end\n"

echo ">>> Debug"
./build_debug.sh
./test.sh
./clean.sh

echo -e "\n>>> Coverage collector"
./build_gcov.sh
./collect_coverage.sh
./clean.sh

echo -e "\n>>> Address sanitizer"
./build_debug_asan.sh
./test.sh
./clean.sh

echo -e "\n>>> Memory sanitizer"
./build_debug_msan.sh
./test.sh
./clean.sh

echo -e "\n>>> Undefined behavior sanitizer"
./build_debug_ubsan.sh
./test.sh
./clean.sh
