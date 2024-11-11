#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "header.h"


void popunjavanjeMatricepseudom(float** mat, int m, int n, float min, float max) {
	srand((unsigned)time(NULL));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = max + (float)rand() / RAND_MAX * (max - min);
		}
	}
}

void ispisivanjeMatrice(float** mat, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%8.2f ", mat[i][j]);
		}
		printf("\n");
	}
}