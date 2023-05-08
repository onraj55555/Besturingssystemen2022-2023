#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char ** argv) {
	struct stat s;
	stat(argv[1], &s);
	printf("%ld\n", s.st_mtim.tv_sec);
	return 0;
}
