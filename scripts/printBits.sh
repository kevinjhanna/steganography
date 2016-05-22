#!/bin/bash

# usage: ./printBits fun.wav

file=$1
length=$2

if [[ -n "$file" ]]; then
  if [[ -n "$length" ]]; then
    xxd -b -l $length Wavs/$file
  else
    xxd -b Wavs/$file
  fi
else
    echo "argument error"
fi
