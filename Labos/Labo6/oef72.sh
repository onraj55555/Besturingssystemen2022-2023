#!/bin/bash

echo "Mijn naam is $0, ik heb als PID $$ en heb $# aantal argumenten"

var=$#
echo Mijn laatste argument is ${!var} # !var => neem de naam die in var zit

