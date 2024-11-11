#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void popunjavanjeMatrice(short**, int);

short** zauzimanjeMatrice(int);

int** brisanjeMatrice(short**, int);

void ispisMatrice(short**, int);

short najveciParnibroj(short**, int);

void novaMatrica(short**, int, int);

void popunjavanjeMatrice(short** matrica, int m) {

	int i, j;
	int donjaGranica = -1550;
	int gornjaGranica = 250;
	srand((unsigned)time(NULL));

	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			*(*(matrica + i) + j) = donjaGranica + (float)rand() / RAND_MAX * (gornjaGranica - donjaGranica);
		}
	}
}

short** zauzimanjeMatrice(int m) {

	int i;

	short** matrica = NULL;

	matrica = (short int**)calloc(m, sizeof(short int*));

	if (matrica == NULL) {
		return NULL;
	}

	for (i = 0; i < m; i++) {
		*(matrica + i) = (short int*)calloc(m, sizeof(short int));
		if (*(matrica + i) == NULL) {
			return NULL;
		}
	}
	return matrica;
}

int** brisanjeMatrice(short** matrica, int m) {
	int i;

	for (i = 0; i < m; i++) {
		free(*(matrica + i));
	}
	free(matrica);
}

void ispisMatrice(short** matrica, int m) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			printf("%5hd", *(*(matrica + i) + j));
		}
		printf("\n");
	}
}

short najveciParnibroj(short** matrica, int m) {
	short rezultat = -5555;
	int i, j;

	rezultat = *(*(matrica + 1) + (m - 1));

	printf("Prvi rezultat je %hd\n", rezultat);

	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			if ((i + j) > (m - 1)) {
				if ((*(*(matrica + i) + j) % 2 == 0) && (rezultat < *(*(matrica + i) + j))) {
					rezultat = *(*(matrica + i) + j);
				}
			}
		}
	}
	return rezultat;
}

void novaMatrica(short** matrica, int m, int broj) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			if ((i + j) < (m - 1)) {
				*(*(matrica + i) + j) = broj;
			}
		}
	}
}