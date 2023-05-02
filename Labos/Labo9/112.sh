#!/bin/bash

directory=""
size=0

while read -r lijn;do
	#echo $(grep -E "* bytes free$")
	#directory=$(grep -E "Directory of *$" <<< $lijn)
	#bytes=$(grep -E "* bytes free$" <<< $lijn)
	#echo $directory
	#echo $bytes
	if [[ "$lijn" =~ "Directory of" ]];then
		directory=$lijn
	fi
	if [[ "$lijn" =~ "bytes free" ]];then
		#size_raw=$((cut -d' ' -f1 <<< $lijn))
		read size rest <<< "$lijn"
		size=${size//./}
		((size<80*1024*1024)) && echo $directory
		#echo $size
	fi
done <pagefile.out
