#!/bin/bash
file_stream_in="${1}"
file_app_args=""

if [ $# -gt 1 ]; then
  file_app_args=$(cat "${2}")
fi

my_array=($(echo $file_app_args | tr " " " "))
first=""
second=""
third=""
third=""
j=0
for i in "${my_array[@]}"; do
  if test $j -eq 0; then
    first="$i"
    j=1
  elif test $j -eq 1; then
    second="../../$i"
    j=2
  elif test $j -eq 2; then
    third="../../$i"
    j=3
  else 
    fourth="../../$i"
  fi
done

if [ -n "$USE_VALGRIND" ]; then
  eval "valgrind --log-file=valgrind_out.txt -q ../../app.exe ../../$file_app_args ./program_out.txt"
else 
  eval "../../app.exe $first $second $third $fourth" &>/dev/null
fi

if test $? -ne 0; then
  exit 0
else
  exit 1
fi