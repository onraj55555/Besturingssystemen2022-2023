#!/bin/bash

while read l1 l2 l3 ; do
	#[[ "$l1 $l2" == "Reply from"]] && echo Found one
	if [[ "$l1 $l2" == "Reply from" ]]
	then
		echo $l3
	fi
done < 'a.out'
