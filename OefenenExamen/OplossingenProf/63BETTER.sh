#!/bin/bash

IFS=: read a b c d < /etc/passwd
echo $a
echo $b
echo $c
echo $d
