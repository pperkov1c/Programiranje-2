#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_M 30
#define MAX_N 10

typedef struct tocka {
	float x;
	float y;
} TOCKA;

typedef struct trokut {
	TOCKA* v1;
	TOCKA* v2;
	TOCKA* v3;
} TROKUT;

int Index(int max_index) {
	return rand() % max_index;
}

float udaljenost(TOCKA* tocka) {
	return sqrt(tocka->x * tocka->x + tocka->y * tocka->y);
}

int main(void) {
	int m, n;
	printf("Unesite m (3 <= m <= 30) i n (1 <= n <= 10):\n");
	scanf("%d %d", &m, &n);

	TOCKA* tocke = (TOCKA*)malloc(m * sizeof(TOCKA));
	TROKUT* trokuti = (TROKUT*)malloc(n * sizeof(TROKUT));

	for (int i = 0; i < m; i++) {
		printf("Unesite koordinate x, y za tocku %d:\n", i + 1);
		scanf("%f %f", &tocke[i].x, &tocke[i].y);
	}

	for (int i = 0; i < n; i++) {
		trokuti[i].v1 = &tocke[Index(m)];
		trokuti[i].v2 = &tocke[Index(m)];
		trokuti[i].v3 = &tocke[Index(m)];
	}

	int minimum = 0, maximum = 0;
	float pocetna_udaljenost = udaljenost(trokuti[0].v1) + udaljenost(trokuti[0].v2) + udaljenost(trokuti[0].v3);
	float max_udaljenost = pocetna_udaljenost;

	for (int i = 1; i < n; i++) {
		float udaljenost_stranice = udaljenost(trokuti[i].v1) + udaljenost(trokuti[i].v2) + udaljenost(trokuti[i].v3);
		if (udaljenost_stranice < pocetna_udaljenost) {
			pocetna_udaljenost = udaljenost_stranice;
			minimum = i;
		}
		if (udaljenost_stranice > max_udaljenost) {
			max_udaljenost = udaljenost_stranice;
			maximum = i;
		}
	}



	printf("Trokut %d ima udaljenost %.2f s koordinatama %f %f %f\n", maximum + 1, max_udaljenost / 3, trokuti[maximum].v1->x, trokuti[maximum].v2->x, trokuti[maximum].v3->x);

	free(tocke);
	free(trokuti);

	return 0;
}

