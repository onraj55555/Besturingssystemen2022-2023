#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char ** argv) {
    int pid=fork();
    if(pid==0) {
        printf("Im the child with pid=%d\n", getpid());
        execl("usr/bin/ls","ls","-l","-i",(char*)0);
        exit(0);
    }
    else if(pid < 0) {
        perror(argv[0]);
        exit(1);
    }
}