## Labo 2
cp: copy file, cp file dir, -s voor symbolische link (pointer)

dd: convert and copy file, dd file conv=TYPE

ln: make links between files

mktemp: make temp file or directory, -d directory, zonder switch is temp file, XXX gaat een bestand aanmaken met 6 verschillende tekens

touch: change file timestamps

OP EXAMEN: touch * zodat iedere file zogezegd aangeraakt is

head: eerste paar lijnen van file uitschrijven
tail: laatste paar lijnen van file uitschrijven

Random 64-bit getal: head -c 8 /dev/urandom | od -An -tu8

ll /dev/urandom, er staan 2 nummers: major en minor nummer

Bestanden verwijderen waarin de naam een - staat, vb -rm: voeg -- toe op het ende om te tonen dat je aan het einde van alle opties zit

wc -c file of leeg laten voor stdin: grootte van de file, HOE AFSLUITEN???

manual pages voor bash interne commando's: help commando

cd -: ga terug naar vorige map verplaatsing (vb bij grote verplaatsingen)

: handig voor oneindige lussen want "always succesfull", null commando

sync: alles in cash op een schijf schrijven naar de schijf

image maken met een bepaald commando

## Labo 4
### Regex
- ^ -> begin v/d lijn
- $ -> einde v/d lijn
- . -> willekeurig teken, 1!
- \* -> 0 - inf keren hetgeen er vooraf staat, r\* == 0 of meer r
- + -> zelfde als ster maar 1 - inf
- ? -> mag maar moet niet, dus ar? en as? zelfde denk ik
- \[a-z\] -> \[^a-z\] ???
- ( ) -> groeperen
- { , } -> min, max van hetgene ervoor, \[aeiou\]{1, 5} == 5 opeenvolgende willekeurige klinkers

\[^/\] == alles behalve een /


Vb: woorden met min 7 klinkers gevolgd door een willekeurig teken
(\[aeiouy\].\*){7,}

Vb: of iets een getal is, GOED KENNEN
^[0-9]+$
Zorgen dat bvb 09 niet mag: (^[1-9]\[0-9\]\*|^0$) maar denk het niet

Vb: 2 keer zelfde combinatie vinden
(\[aeouiy\]{2,}).\*\\1

IP-adres zoeken: xyz.xyz.xyz/xy, kan ook minder getallen

### Find
find startmap test1 test2 test3

Oef 48: sudo find /etc -type f | grep -E "/pass[^/]\*$"
Oef 49: sudo find /etc -type d -name sh*
Oef 50: sudo find / -type f -size +1M -exec du -h {} \\; OF sudo find / -type f -size +1M -printf "%s %p\\n"|less

## Labo 6
### Bash
#### Testing
```BASH
test is hetzelfde als [ ... ]
if [[ $a =~ 5 ]]     a bevat cijfer 5
if test $a -eq 5     a is 5
```

#### Variabelen en functies
```BASH
${var}
$(command) -> command substitution

var=a
a=hallo
-> echo ${!var} print inhoud van variabele die in var zit
```

Commentaar: #

Toevoegen aan path: PATH=$PATH:. huidige map aan path toevoegen, nutteloos?

```BASH
#!/bin/bash

read a b c d < /etc/passwd
echo $a
echo $b
echo $c
echo $d
```
d krijgt al de overschot

Splits op spatie en \\n, IFS aanpassen om anders te splitsen
```BASH
IFS=$' \t\n'
```

#! toevoegen gevolgd door interpreter, bv bash, python, ...

Tabel printen
```BASH
echo ${tab[@]}  PRINT ALLE WAARDEN
echo ${!tab[@]} PRINT ALLE KEYS, indexen, hashvalues???
echo ${#tab[@]} PRINT GROOTTE
```

Positionele parameters: ./script a b 1
$1 = a
$2 = b
$3 = 1
Aantal parameters: $#
Stel $13: ${13}

### Labo 6 ??
Aantal argumenten voor bash script: $#
PID bash script: \$\$
Laatste element: var=\$#, laatste=\${!var}

Over alle parameters overlopen
```bash
for i in $@;do
	echo i
done
```
Opletten als parameter en spatie bevat: a "b c" d, oplossen: "$@"

\$\* bevat hetzelfde als \$@ maar doen iets anders wanneer je er " " rond zet
"\$@" -> "\$1", "\$2", ...
echo "\$\*": echo\$1\$IFS\$2\$IFS...

#### Forkbom
f(){f|f&};f -> :(){:|:&};:
In script
```bash
function f() {
	f|f&
}
```
De & betekend: in de achtergrond starten, handig voor lange processen zodat je terminal bruikbaar blijft

pkill: processkill, vb: pkill tar, stopt alle tar processen

Lokale var maken in script: local var=...

#### Array
```bash
array=(_ _ _ _ ...) # gescheiden door IFS (internal field seperator)
array=([0]=hallo [2]=daar) OF array=(hallo daar) => [0]=hallo, [1]=daar
echo ${!array[@]} # sleutels in array
echo ${array[@]} # waardes in array

unset array[INDEX] # INDEX weg smijten
```

## Labo 7

Oef 89
```BASH
IF TESTEN TOEVOEGEN
if(($#!=1));then
	echo "Fout: te veel" >&2 # Schrijven naar stderr
	exit 1
fi

if [[ ! -f "$1" ]];then
	echo "Fout: parameter is geen regulier bestand" >&2
	exit 1
fi

#!/bin/bash

read l w c f < <(wc "$1") # alles lezen uit wc
#echo $l $w $c $f

echo Gemiddeld aantal woorden per lijn: $(((w+l/2)/l)) # we doen (w+l/2)/l om de juiste afronding te hebben (T + helft van N)
echo Gemiddeld aantal karakters per lijn: $(((c+l/2)/l))

# NU MET ARRAY

#!/bin/bash

array=($(wc "$1"))
echo ${array[@]}
l=${array[0]}
w=${array[1]}
c=${array[2]}
f="${array[3]}" # " " nodig want is een string met mogelijke spaties

echo Gemiddeld aantal woorden per lijn: $(((w+l/2)/l)) # we doen (w+l/2)/l om de juiste afronding te hebben (T + helft van N)
echo Gemiddeld aantal karakters per lijn: $(((c+l/2)/l))
```

Oef 90
```
IFS=$IFS: ???
```

### Tussenin: variabelen en meer
```BASH
var=..... # Hard coderen
echo $var

var=$(cmd) # Als output van commando

var=$((a+=b)) # Vervangen door resultaat van a+=b

< bestand # SPATIE BELANGRIJK
<<< "string"
< <(cmd) # SPATIE BELANGRIJK

cmd1 | cmd2 ZELFDE ALS cmd1 > >(cmd2) # cmd2 in subshell
cmd2 < <(cmd1) # cmd1 in subshell

>>
> >(...)
```

Oef 91
```BASH
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
KAN OOK
IFS=: read naam rest REGEX MET GREP
echo $naam

BETERE CHECK IN HET BEGIN

# =~ leest ook een regex en is beter dan grep want is een intern commando
if (($#!=1)) || [[ ! "$1" =~ (^[1-9][0-9]*$)|(^0$) ]];then
	echo "Fout bij eerste en enige parameter" >&2
fi
```

### While
```BASH
while cmd;do # Blijft tot cmde exitstatus 0 heeft
	...
done

of

while cmd
do
	...
done

# Lezen bestand
while read lijn
do
	echo $lijn
done < file

# Iets met een teller
tel=0
while ((tel < 100)); do
	echo $tel
	((tel++))
done