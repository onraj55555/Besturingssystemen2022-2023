#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void vul_buffer(unsigned char* buffer, int n) {
    for(int i = 0; i< n; i++) {
        buffer[i] = rand()%26 + 'a';
    }
}

int main(int argc, char **argv) {
    srand(getpid());
    unsigned char buffer[BUFSIZ];
    vul_buffer(buffer, BUFSIZ);
    for(int i =2*2*2*2;i<=BUFSIZ;i*=2) {
        double start=clock();
        int fd=open("file",O_WRONLY|O_CREAT);
        if (fd<0){
            perror(argv[0]);
            exit(1);
        }
        int tot=0;
        for(int j=0;j<10*1024*1024-i;j+=i){
            write(fd,buffer,i);
            tot+=i;
        }
        tot+=write(fd,buffer,10*1024*1024-tot);
        close(fd);
        printf("BUFSIZ=%d TOT=%d TIME=%.2f\n",i,tot,(clock()-start)/CLOCKS_PER_SEC);
        unlink("file");
    }
    // unlink("file"); //verwijderen bestand
    return 0;
}
