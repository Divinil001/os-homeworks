#! /bin/bash

if [ $# -lt 1 ]; then
    echo "Usage:"
    echo "$0 filename"
    exit
fi

size ex2 | awk  '{print $1, $2, $3}' > ex1.txt