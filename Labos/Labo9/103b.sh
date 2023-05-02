#!/bin/bash

if (($#!=0));then

	eerste=0
	while read pid tty tijd commando ; do
		if ((eerste!=0));then
			for i in "$@";do # " " nodig om parameter met spatie toch als 1 te beschouwen
				[[ "$i" == "$commando" ]] && echo "kill -15 $pid"
			done
		else
			eerste=1
		fi
	done < <(ps -e)
else
	eerste=0
	declare -A array
	while read pid tty tijd cmd;do
		((eerste==0)) && eetste=1 || array["$cmd"]=1
	done < <(ps -e)

	for i in ${!array[@]};do
		echo $i
	done | sort
fi


