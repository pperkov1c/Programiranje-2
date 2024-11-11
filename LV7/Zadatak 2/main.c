#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {

	float mat[5][5];
	float dg = -125.5;
	float gg = 65.8;
	int m, n;

	srand((unsigned)time(NULL));

	FILE* fp = NULL;

	const char* primjer = "in.txt";

	fp = fopen(primjer, "r");

	if (fp == NULL) {

		printf("Datoteka %s ne postoji na disku.\n", primjer);

	}
	else {

		printf("Datoteka %s postoji na disku.\n", primjer);

		fscanf(fp, "%d\n%d", &m, &n);

		printf("m je %d, a n %d.\n", m, n);

		fclose(fp);

	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			*(*(mat + i) + j) = dg + (float)rand() / RAND_MAX * (gg - dg);
			printf("%8.2f ", *(*(mat + i) + j));
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");

	FILE* wp = NULL;
	wp = fopen("out.txt", "w");
	int priv = 0;

	if (wp == NULL)
	{
		printf("Datoteka se ne moze kreirati.");
	}
	else {
		for (int i = 0; i < m - 1; i++) {
			for (int j = 1; j < n; j++) {
				priv = fprintf(wp, "%f ", *(*(mat + i) + j));
				printf("%8.2f ", *(*(mat + i) + j));
			}
			priv = fprintf(wp, "\n");

			printf("\n");
		}
		fclose(wp);
	}

	return 0;
}