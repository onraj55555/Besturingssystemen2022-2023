#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define N 4

void * worker(void * p) {
	int * p2 = (int *) p;
	for(int i = 0; i < 1000; i++) {
		printf("%d", *p2);
	}
	return 0;
}

int main(int argc, char ** argv) {
	pthread_t array[N];
	int args[] = {0, 1, 2, 3};
	for(int i = 0; i < N; i++) {
		pthread_create(&array[i], NULL, worker, (void*)&args[i]);
	}
	for(int i = 0; i < N; i++) {
		pthread_join(array[i], NULL);
	}
	return 0;
}
