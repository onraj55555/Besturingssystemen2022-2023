#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char ** argv) {
	srand(getpid());
	int fd=open("file", O_WRONLY|O_CREAT);
	if(fd < 0) {
		return 1;
	}
	for(int i = 0; i < 10*1024*1024; i++) {
		unsigned char ch=rand()%26 + 'a';
		write(fd, &ch, sizeof(ch));
	}
	close(fd);
	//unlink("file");
	return 0;
}
