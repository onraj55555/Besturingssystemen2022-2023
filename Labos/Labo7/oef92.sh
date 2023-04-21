#!/bin/bash

if (($#>2)) || (($# == 0));then
	echo "Te vele of te weinig" >&2
	exit 1
fi

if [[ ! -f "$1" ]];then
	echo "$1 is geen geldig bestand" >&2
	exit 1
fi

read l n < <(wc -l "$1")

teller=0
while read lijn;do
	if ((teller>=$((l-${2-10}))));then
		echo $lijn
	fi
	((teller++))
done < "$1"
