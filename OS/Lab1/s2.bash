#!/bin/bash
check=a
ans=
while [[ $check != q ]]
do
read check
ans+="$check"
done
echo $ans
