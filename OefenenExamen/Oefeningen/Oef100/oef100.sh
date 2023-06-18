#!/bin/bash

declare -A params
for i in "$@";do
	count=${params[$i]-0}
	params[$i]=$((count+1))
done

for i in "$(${!params[@]} | sort)";do
	echo $i komt ${params[$i]} keer voor
done
