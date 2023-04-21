#!/bin/bash

x="dit is een <b>eenvoudige</b> en <b>nuttige</b> oefening"

s1=${x#*<b>}
s1=${s1%%</b>*}
echo $s1

s2=${x##*<b>}
s2=${s2%</b>*}
echo $s2
