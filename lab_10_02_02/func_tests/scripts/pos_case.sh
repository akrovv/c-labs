#!/bin/bash

file_stream_in="${1}"
file_stream_out_expect="${2}"
file_app_args=""

if [ $# -gt 2 ]; then
  file_app_args=$(cat "${3}")
fi

if [ -n "$USE_VALGRIND" ]; then
  eval "valgrind --log-file=valgrind_out.txt -q ../../app.exe ../$file_app_args ./program_out.txt"
else
  eval "../../app.exe < $file_stream_in > ./program_out.txt" 
fi

if test $? -ne 0; then
  exit 1
fi

bash ./comparator.sh "$file_stream_out_expect" "./program_out.txt"

if test $? -eq 0; then
  exit 0
else
  exit 1
fi
