#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int * array;
	int n;
	int (*f)(int *, int);
} t_arg;

int bepaal_grootste(int * array, int n) {
	int g = array[0];
	for(int i = 1; i < n; i++) {
		if(array[i] > g) {
			g = array[i];
		}
	}
	return g;
}

void * worker(void * p) 

