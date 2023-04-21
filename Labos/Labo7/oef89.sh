#!/bin/bash

read l w c f< <(wc "$1") # alles lezen uit wc
#echo $l $w $c $f

echo Gemiddeld aantal woorden per lijn: $(((w+l/2)/l)) # we doen (w+l/2)/l om de juiste afronding te hebben (T + helft van N)
echo Gemiddeld aantal karakters per lijn: $(((c+l/2)/l))
