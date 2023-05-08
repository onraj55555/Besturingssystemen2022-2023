#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

int main(int argc, char ** argv) {
	if(argc != 3) {
		fprintf(2, "Argumenten niet juist\n");
	}
	unsigned char buffer[1024*1024];
	int fd1=open(argv[1], O_RDONLY);
	int fd2=open(argv[2], O_WRONLY|O_CREAT);
	if(fd1 < 0) {
		fprintf(stderr, "Openen %s niet gelukt\n", argv[1]);
		exit(1);
	}
	if(fd2 < 0) {
		fprintf(stderr, "Openen %s niet gelukt\n", argv[2]);
		exit(1);
	}
	int n = read(fd1, buffer, 1024*1024);
	while(n > 0) {
		write(fd2, buffer, n);
		n = read(fd1, buffer, 1024*1024);
	}
	close(fd1);
	close(fd2);
	return 0;
}
