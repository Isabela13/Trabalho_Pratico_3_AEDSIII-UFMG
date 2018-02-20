#include <stdio.h>
#include <stdlib.h>

#include "operacoes.h"

void LiberaMatriz(int n, int **M){
	int i;
	for(i=0;i<n;i++){
		free(M[i]);
	}
	free(M);

}

void semblocos(int **mat_a, int **mat_b, int N){
	int i,j,k;
	int **mat_c= (int**) malloc((N)*sizeof(int*));
	for (i = 0; i < N; i++){
		mat_c[i] = (int*) malloc((N) * sizeof(int));
	}
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			mat_c[i][j]=0;
			for (k = 0; k < N; k++)
			{
				mat_c[i][j]=mat_c[i][j] + mat_a[i][k]*mat_b[k][j];
			}
		}
	}

	printf("\n");
	for (i = 0; i < N; i++){
		for ( j = 0; j < N; j++){
			printf("%d ",mat_c[i][j]);
		}

		printf("\n");
	}
	printf("\n");
	LiberaMatriz(N,mat_c);
}


void comblocos(int **mat_a, int **mat_b, int N, int bsize){
	int sum,kk,jj,i,j,k;
	int **mat_c= (int**) malloc((N)*sizeof(int*));
	for (i = 0; i < N; i++){
		mat_c[i] = (int*) malloc((N) * sizeof(int));
	}


	for( i = 0; i < N;i++){
		for (j = 0; j < N; j ++){
			mat_c[i][j] = 0;
		}
	}
	for (kk = 0; kk < N; kk+=bsize){
		for (jj = 0; jj < N; jj+=bsize){
			for( i = 0; i < N;i++){
				for( j = jj; j < jj + bsize; j++){
					sum = mat_c[i][j];
					for (k = kk; k < kk + bsize; k ++){
						sum = sum + mat_a[i][k] * mat_b[k][j];
					}
					mat_c[i][j] = sum;
				}
			}
		}
	}
	
	printf("\n");
	for (i = 0; i < N; i++){
		for ( j = 0; j < N; j++){
			printf("%d ",mat_c[i][j]);
		}

		printf("\n");
	}
	LiberaMatriz(N,mat_c);
	printf("\n");
}

