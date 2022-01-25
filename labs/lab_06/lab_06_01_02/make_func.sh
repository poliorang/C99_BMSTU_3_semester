#!/bin/bash

cd func_tests || exit

sh all_test.sh
cd ..

echo
echo -e "\e[33mCoverage main.c\e[0m"
gcov main.c -r
echo -e "\e[33mCoverage objects.c\e[0m"
gcov objects.c -r
