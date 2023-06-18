#!/bin/bash

faculteit(){
	res=1
	for((i=$1;i>1;i--));do
		((res*=i))
	done
	return $res
}

faculteit 5
echo $?

#grootte van return-waarde is beperkt, dus ...

faculteit(){
	res=1
	for((i=$1;i>1;i--));do
		((res*=i))
	done
	echo $res
}

echo Faculteit van 5 is $(faculteit 5)
