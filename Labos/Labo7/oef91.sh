#/bin/bash

# /etc/passwd: root:x:uid:grid:...
# bash oef91.sh getal

if (($#!=1));then
	echo "Te veel parameters!" >&2
	exit 1
fi

IFS=\n
getal=$1
var=$(cat /etc/passwd | grep -E "^.+:x:$getal:.+$")
IFS=":"
read naam x uid rest <<<"$var"
echo $naam

