#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int fd[2];
    if(pipe(fd)<0) {
        perror(argv[0]);
        exit(1);
    }
    int id=fork();
    if(id == 0) {
        close(fd[1]);
        int g;
        srand(getpid());
        printf("The child has generated %d\n", rand());
        exit(0);
    }
    else if(id < 0) {
        perror(argv[0]);
        exit(1);
    }
}