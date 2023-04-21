#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char itoc(int g) {
    char zetom[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    return zetom[g];
}

int main(int argc, char ** argv) {
    char in[BUFSIZ];
    char out[BUFSIZ*2];
    for(int i = 1; i < argc; i++) {
        int fd = open(argv[i], O_RDONLY);
        if(fd < 0) {
            perror(argv[i]);
            continue;
        }
        /*struct stat sb;
        stat(fd, &sb);
        if((sb.st_mode & S_IFMT) != S_IFREG) {
            close(fd);
            continue;
        }*/
        int n = read(fd, in, BUFSIZ);
        while(n > 0) {
            int k = 0;
            for(int j = 0; j < n; j++) {
                out[k+1] = itoc(in[j]%16);
                out[k] = itoc(in[j]/16);
                k += 2;
            }
            write(1, out, n*2);
            n = read(fd, in, BUFSIZ);
        }
        if(n < 0) {
            perror(argv[i]);
            close(fd);
            continue;
        }
        close(fd);
    }

    return 0;
}