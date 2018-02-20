#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"

int main(){
	int N, bsize, i,j;
	if(scanf("%d %d", &N, &bsize) == 0) exit(-1);
	int **mat_a= (int**) malloc((N)*sizeof(int*));
	int **mat_b= (int**) malloc((N)*sizeof(int*));
	for (i = 0; i < N; i++){
		mat_a[i] = (int*) malloc((N) * sizeof(int));
		mat_b[i] = (int*) malloc((N) * sizeof(int));
	}

	for (i = 0; i < N; i++){
		for ( j = 0; j < N; j++){
			if(scanf("%d",&mat_a[i][j]) == 0) exit(-1);
		}
	}

	for (i = 0; i < N; i++){
		for ( j = 0; j < N; j++){
			if(scanf("%d",&mat_b[i][j]) == 0) exit(-1);
		}
	}
	
	

    semblocos(mat_a, mat_b,  N);
	comblocos(mat_a, mat_b,  N, bsize);

	
	LiberaMatriz(N,mat_a);
	LiberaMatriz(N,mat_b);

	return 0;
}


