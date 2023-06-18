#!/bin/bash

read a b c d < /etc/passwd
echo "START"
echo $a
echo $b
echo $c
echo $d
echo "END"
