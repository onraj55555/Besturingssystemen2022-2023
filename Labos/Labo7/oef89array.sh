#!/bin/bash

array=($(wc "$1"))
echo ${array[@]}
l="${array[0]}"
w="${array[1]}"
c="${array[2]}"
f="${array[3]}"

echo Gemiddeld aantal woorden per lijn: $(((w+l/2)/l)) # we doen (w+l/2)/l om de juiste afronding te hebben (T + helft van N)
echo Gemiddeld aantal karakters per lijn: $(((c+l/2)/l))
