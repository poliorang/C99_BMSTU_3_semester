#!/bin/bash

ok=0
error=1

file=$1
num=${file:4:2}
file_args=neg_${num}_args.txt

$(cat "$file_args") 

file_one=neg_${num}_in.txt

res=$(python func_tests.py $(cat "$file_args") )

if [ $res -eq 0 ]
then
  echo -e "${file_one} \e[32mPASSED\e[0m"
  exit ${ok}
else
  echo -e "${file_one} \e[31mFAILED\e[0m"
  exit ${error}
fi
