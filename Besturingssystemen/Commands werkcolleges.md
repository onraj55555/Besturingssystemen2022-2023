valgrind ./a.out: memoryleaks detecteren
strace ./a.out: onderschept was programma aan OS vraagt
/usr/bin/time ./a.out
ps -aux: opties -a, -u -x -> -aux, veel info over proces (vb wie heeft opgestart, ...), pts/0 is terminal 0, pts/1 is terminal 1, ..., niet real time
top: real time info, teal time ps -aux
htop: geafanceerde versie can top, nog veel zoeken ermee!

Hoe nicer in linux, hoe lagere prioriteit t.o.v. andere processen
F8 in htop, daar kan je 