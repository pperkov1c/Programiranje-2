#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "header.h"

int main() {

	int i, j;
	int m;
	int donjaGranica = 4;
	int gornjaGranica = 18;
	short** matrica = NULL;
	int broj;

	srand((unsigned)time(NULL));

	m = donjaGranica + (float)rand() / RAND_MAX * (gornjaGranica - donjaGranica);

	printf("Broj redova i stupaca je %d.\n", m);

	matrica = zauzimanjeMatrice(m);

	popunjavanjeMatrice(matrica, m);

	ispisMatrice(matrica, m);

	broj = najveciParnibroj(matrica, m);

	printf("Najveci parni broj ispod sporedne dijagonale je %hd.\n", broj);

	novaMatrica(matrica, m, broj);

	ispisMatrice(matrica, m);

	matrica = brisanjeMatrice(matrica, m);

	return 0;
}