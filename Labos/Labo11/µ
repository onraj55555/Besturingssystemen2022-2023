// Stappenplan
// 1) Maak n-processen aan en wacht
// 2) Gereneer per kind een random getal met SRAND en print deze uit
// 3) Per kind, zend getal naar parent (met pipe) en in parent uit printen

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char ** argv) {
	const int aantal = atoi(argv[1]);
	int pids[aantal];
	int fd[aantal][2];
	int fd2[aantal][2];
	for(int i = 0; i < aantal; i++) {
		if(pipe(fd[i]) == -1) {
			exit(1);
		}
		if(pipe(fd2[i]) == -1) {
			exit(2);
		}

		int pid = fork();
		if(pid == 0) {
			close(fd[i][0]);
			close(fd2[i][1]);
			srand(getpid());
			printf("Ik ben een kind met pid=%d\n", getpid());
			int g = rand() % 100;
			printf("Ik kan tot %d tellen\n", g);
			write(fd[i][1], &g, sizeof(g));
			close(fd[i][1]);
			int status;
			read(fd2[i][0], &status, sizeof(status));
			if(status == getpid()) {
				printf("Ik (%d) ben de winnaar\n", getpid());
			}
			close(fd2[i][0]);
			return 0;
		}
		else {
			close(fd[i][1]);
			close(fd2[i][0]);
			pids[i]=pid;
		}
	}	
	int beste = 0;
	int max = 0;
	for(int i = 0; i < aantal; i++) {
		int g;
		read(fd[i][0], &g, sizeof(g));
		if(g > max) {
			beste = i;
			max = g;
		}
	}
	for(int i = 0; i < aantal; i++) {
		write(fd2[i][1], &beste, sizeof(beste));
		close(fd2[i][1]);
	}


	return 0;
}

