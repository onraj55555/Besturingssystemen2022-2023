#include <stdio.h>

#define DIM 2

typedef struct {
	int (*a)[DIM];
	int (*b)[DIM];
	int (*c)[DIM];
	void (*f)(int (*)[DIM], int (*)[DIM], int (*)[DIM]);
} data_t;

void matmul(int (*a)[DIM], int (*b)[DIM], int (*c)[DIM]) {
	for(int i = 0; i < DIM; i++) {
		for(int j = 0; j < DIM; j++) {
			int som = 0;
			for(int k = 0; k < DIM; k++) {
				som += a[i][k]*b[k][j];
			}
			c[i][j] = som;
		}
	}
}

