#!/bin/bash

x="dit is een <b>nuttige</b> en <b>eenvoudige</b> oefening"
a=${x#*>}
a=${a%%<*}

b=${x##*<b>}
b=${b%<*}

echo $a $b
