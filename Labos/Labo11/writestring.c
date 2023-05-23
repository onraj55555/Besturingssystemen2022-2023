#include <stdio.h>
#include <time.h>
#include <unistd.h> // ALLES VOOR SYSTEMCALLS

int main(int argc, char ** argv) {
	printf("pid=%d en het enige argument is: %s\n", getpid(), argv[1]);
	sleep(10);
	return 0;
}

