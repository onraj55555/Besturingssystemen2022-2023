#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
	if(argc == 1) {
		perror(argv[0]);
		exit(1);
	}
	int fd=open(argv[1], O_RDONLY);
	if(fd < 0) {
		perror(argv[1]);
		exit(2);
	}
	char c = 1;
	while(c != 0) {
		read(fd, &c, sizeof(c));
		printf("Gelezen %c\n", c);
	}
	close(fd);
	return 0;
}
	
