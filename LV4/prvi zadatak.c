#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
	float x;
	float y;
} TOCKICE;

typedef struct {
	TOCKICE t1;
	TOCKICE t2;
	TOCKICE t3;
} TROKUTi;

float duzina(TOCKICE* t1, TOCKICE* t2) {
	return sqrt(pow(t2->x - t1->x, 2) + pow(t2->y - t1->y, 2));
}

float opseg(TROKUTi* t) {
	return duzina(&t->t1, &t->t2) + duzina(&t->t2, &t->t3) + duzina(&t->t3, &t->t1);
}

int main() {
	int m, n;

	do {
		printf("Unesite broj tocaka: ");
		scanf("%d", &m);
		if (m < 3 || m>30) {
			printf("Pogresan unos, ponovite unesite broj.\n");
		}
	} while (m < 3 || m > 30);

	do {
		printf("\nUnesite broj trokuta: ");
		scanf("%d", &n);
		if (n < 1 || n>10) {
			printf("Pogresan unos, ponovno unesite broj.\n");
		}
	} while (n < 1 || n > 10);



	TOCKICE* tocke = (TOCKICE*)malloc(m * sizeof(TOCKICE));
	TROKUTi* trokutovi = (TROKUTi*)malloc(n * sizeof(TROKUTi));



	for (int i = 0; i < n; i++) {
		printf("\nUnesite koordinate %d. trokuta: ", i + 1);
		scanf("%f %f %f %f %f %f", &((trokutovi + i)->t1.x), &((trokutovi + i)->t1.y), &((trokutovi + i)->t2.x), &((trokutovi + i)->t2.y), &((trokutovi + i)->t3.x), &((trokutovi + i)->t3.y));
	}

	float maksimumOpseg = opseg(trokutovi);
	int maksimumIndex = 0;

	for (int i = 1; i < n; i++) {
		float opsegg = opseg(trokutovi + i);
		if (opsegg > maksimumOpseg) {
			maksimumOpseg = opsegg;
			maksimumIndex = i;
		}
	}

	printf("\nTrokut %d ima opseg %.2f s koordinatama %f %f %f %f %f %f",
		maksimumIndex + 1,
		maksimumOpseg,
		(trokutovi + maksimumIndex)->t1.x,
		(trokutovi + maksimumIndex)->t1.y,
		(trokutovi + maksimumIndex)->t2.x,
		(trokutovi + maksimumIndex)->t2.y,
		(trokutovi + maksimumIndex)->t3.x,
		(trokutovi + maksimumIndex)->t3.y);

	free(tocke);
	free(trokutovi);
	return 0;
}