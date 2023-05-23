#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
	int pids[3];
	for(int i = 0; i < 3; i++) {
		pids[i] = fork();
		if(pids[i] == 0) {
			// CHILD
			printf("Child %d started\n", getpid());
			return 0;
		}
	}

	for(int i = 0; i < 3; i++) {
		waitpid(pids[i], NULL, 0);
	}
	return 0;
}
