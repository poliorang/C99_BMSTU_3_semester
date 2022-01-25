#!/bin/bash

ok=0
error=1

file=$1
num=${file:4:2}
file_args=neg_${num}_args.txt

../app.exe "$(cat "$file_args")" >out.txt

file_one=neg_${num}_out.txt
file_two=out.txt

res=$(python comparator.py "$file_one" "$file_two")

if [ "$res" -eq 0 ]
then
  echo -e "${file_one} \e[32mPASSED\e[0m"
  rm out.txt
  exit ${ok}
else
  echo -e "${file_one} \e[31mFAILED\e[0m"
  rm out.txt
  echo
  exit ${error}
fi
