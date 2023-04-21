#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    int fd_PC1[2];
    int fd_PC2[2];
    int fd_C1C2[2];
    pipe(fd_PC1);
    pipe(fd_PC2);
    pipe(fd_C1C2);
    int pid_C1 = fork();
    if(pid_C1 == 0) {
        // CHILD 1
	
	close(fd_PC2[0]);
	close(fd_PC2[1]);
	close(fd_C1C2[0]);
	close(fd_PC1[1]);
	int h;
	read(fd_PC1[0], &h, sizeof(int));
	printf("%d received from PARENT\n", h);
	h *= 2;
	write(fd_C1C2[1], &h, sizeof(int));
	printf("%d send to CHILD 2\n", h);
        return 0;
    }
    int pid_C2 = fork();
    if(pid_C2 == 0) {
        // CHILD 2
	close(fd_PC1[0]);
	close(fd_PC1[1]);
	close(fd_C1C2[1]);
	close(fd_PC2[1]);
	int n1, n2;
	read(fd_C1C2[0], &n1, sizeof(int));
	printf("%d reveiced from CHILD 1\n", n1);
	read(fd_PC2[0], &n2, sizeof(int));
	printf("%d received from PARENT\n", n2);
	printf("Sum is %d\n", n1+n2);
        return 0;
    }
    // PARENT
    srand(getpid());
    int gC1 = rand()%20;
    int gC2 = rand()%20;
    close(fd_C1C2[0]);
    close(fd_C1C2[1]);
    close(fd_PC1[0]);
    close(fd_PC2[0]);
    write(fd_PC1[1], &gC1, sizeof(gC1));
    printf("%d send to CHILD 1\n", gC1);
    write(fd_PC2[1], &gC2, sizeof(gC2));
    printf("%d send to CHILD 2\n", gC2);
    waitpid(pid_C2, NULL, 0);
    waitpid(pid_C1, NULL, 0);
    return 0;
}
