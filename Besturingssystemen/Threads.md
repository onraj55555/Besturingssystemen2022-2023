## Multiprocesses
```C
open/close
read/write
fork/waitpid
stat
dup
```

## Threads
```C
pthread_create(pthread_t *, NULL, worker, arg);
worker: void * work(void *);
arg: 1 parameter of een struct van je parameters;

pthread_join(pthread_t, void **);
```

Linker error: gcc -pthread file.c