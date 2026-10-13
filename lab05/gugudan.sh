#!/bin/bash

echo "===== for 반복문 ====="

for i in {2..9}
do
    for j in {1..9}
    do
        echo "$i x $j = $((i * j))"
    done
done

echo "===== while 반복문 ====="

i=2

while [ $i -le 9 ]
do
    j=1

    while [ $j -le 9 ]
    do
        echo "$i x $j = $((i * j))"
        ((j++))
    done

    ((i++))
done

echo "===== until 반복문 ====="

i=2

until [ $i -gt 9 ]
do
    j=1

    until [ $j -gt 9 ]
    do
        echo "$i x $j = $((i * j))"
        ((j++))
    done

    ((i++))
done

