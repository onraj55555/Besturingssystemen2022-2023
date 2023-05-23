#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>

// Maak 3 kinders, print hun naam en watch tot ze gesprongen zijn

int main() {
	int count_children = 1;
	int pid=fork();
	for(int i = 1; i < 3; i++) {
		if(pid > 0) {
			pid=fork();
		}
	}
	if(pid == 0) {
		printf("Ik ben kind met pid %d\n", getpid());
	}
	while(wait(NULL) > -1);
	return 0;
}

