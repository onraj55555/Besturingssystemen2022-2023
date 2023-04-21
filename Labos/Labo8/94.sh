#!/bin/bash

while read -a array ; do
	if [[ "${array[0]}" =~ ^C ]];then
		[[ -n $hostname ]] && echo $hostname
		hostname=${array[3]}
	fi
	[[ "${array[0]}" =~ ^Reply ]] && unset hostname
done < ping.out
