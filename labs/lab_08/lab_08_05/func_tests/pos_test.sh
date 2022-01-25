#!/bin/bash

ok=0
error=1

file=$1
num=${file:4:2}

../app.exe <"$file" >out.txt

file_one=pos_${num}_out.txt
file_two=out.txt

diff "$file_one" "$file_two"
res=$?


if [ $res -eq 0 ]
then
  echo -e "${file_one} \e[32mPASSED\e[0m"
  rm out.txt
  exit ${ok}
else
  echo -e "${file_one} \e[31mFAILED\e[0m"
  rm out.txt
  exit ${error}
fi
