Bash
- text > file en text 1> file en > file text: alles overschrijve dus vorige data in file is weg
- text >> file en text 1>> file: achteraan toevoegen
- text > file1 > file2: file1 blijft leeg, ik denk dat filter daar goed kan gebruikt worden maar misschien niet

Indien je eerst: set -o noclobber hebt gedaan werkt > niet files met data in! Om toch te overschrijven: text >| file
noclobber resetten: set +o noclobber
set -C zelfde als set -o noclobber, reset: set +C

## Positionele parameter accessen
```BASH
echo ${13}
```

## Waarde van var gebruiken om i-de positionele parameter te accessen:
```BASH
x=2
echo ${!x}
```

## Speciale vars
Magpage: man bash -> Special Parameters
$0: naam script
\$\$: unieke PID van script
\$#: aantal argumenten script
\$* en \$@: alle parameters van script in string maar er is een verschil

## String operaties
```BASH
${#var}: lengte var

${var#pattern}: verwijdert kortste substring waarin pattern voorkomt vooraan
${var##pattern}: verwijdert langste substring waarin pattern voorkomt vooraan
${var%pattern}: verwijdert kortste substring waarin pattern voorkomt achteraan
${var%%pattern}: verwijdert langste substring waarin pattren voorkomt achteraan

${var:offset}: geeft string vanaf offset
${var:offset:length}: geeft string vanaf offset die length lang is
${var/pattern/string}: geeft string waarin de 1e langste pattern string geworden is
...
```

## Builtin vars
declare geeft alle huidige vars weer, declare --help voor meer info

## IFS
IFS in script aanpassen
```BASH
IFS=iets cmd DENK IK
```

Appenden aan IFS
```BASH
IFS=$IFS:
```

## While lus om file in te lezen
```BASH
while IFS=lines_split read vars ; do
	bewerkingen
done < "file"
```
