#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define AANTAL 1000000
int tab[AANTAL];

typedef struct {
	int * tab;
	int n;
	int (*f)(int *, int);
} data_t;

int geef_grootste(int * tab, int n) {
	int res = tab[0];
	for(int i = 1; i < n; i++) {
		if(tab[i] > res) {
			res = tab[i];
		}
	}
	return res;
}

int geef_kleinste(int * tab, int n) {
	int res = tab[0];
	for(int i = 1; i < n; i++) {
		if(tab[i] < res) {
			res = tab[i];
		}
	}
	return res;
}

void * worker(void * p) {
	data_t * d = (data_t *)p;
	return d->f(d->tab, d->n);
}

int main() {
	pthread_t thread_g, thread_k;
	data_t data_g, data_k;
	data_g.tab = tab;
	data_k.tab = tab;
	data_g.n = AANTAL;
	data_k.n = AANTAL;
	data_g.f = geef_grootste;
	data_k.f = geef_kleinste;
	pthread_create(&thread_g, NULL, worker, (void *)&data_g);
	pthread_create(&thread_k, NULL, worker, (void *)&data_k);

	int grootste;
	int kleinste;
	pthread_join(thread_g, &grootste);
	pthread_join(thread_k, &kleinste);
	printf("%d is het grootste en %d is het kleinste\n", grootste, kleinste);
	return 0;
}

