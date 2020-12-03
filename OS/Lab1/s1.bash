#!/bin/bash
let ans=$1
if [[ "$1" -lt "$2 ]]
then ans=$2
fi
if [[ "$2" -lt "$3 ]]
then ans=$3
fi
echo $ans
