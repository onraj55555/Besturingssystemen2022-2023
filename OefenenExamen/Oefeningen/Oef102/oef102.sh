#!/bin/bash

echo "$1"

IFS=/ arr=$(echo "$1")

for i in "${arr[@]}";do
	echo $i
done
