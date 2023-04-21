#!/bin/bash

function f() {
	local res=1
	local n=$1
	while ((n>0))
	do
		((res*=N))
		((n--))
	done
	echo $res
	return 0
}
