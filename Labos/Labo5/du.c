#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	struct stat st;
    for(int i = 1; i < argc; i++) {
        int fd = open(argv[i], O_RDONLY);
        if(fd < 0) {
            perror(argv[i]);
            continue;
        }
        if(fstat(fd, &st) < 0) {
            perror(argv[i]);
        }
    }
}
	
