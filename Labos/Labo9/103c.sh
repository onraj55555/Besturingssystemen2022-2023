#!/bin/bash

while [[ -n "$@" ]];do
	case "$1" in
		# flag -f of --file
		-f|--file)
			shift
			[[ ! -z "$1" && -f "$1" ]] || { echo "Usage 104.sh [ -f file ]" >&2 ; exit 1 ; } && echo "f" # -f "$1": testen of $1 een regulier bestand is
			;;
		# flags, al willekeurige tekens?
		-?*)	while read -n1 letter;do
				echo $letter
			done <<< "$1"
			;;
		# geen - dus error hier
		[^-]*)
			;;
	esac
	shift
