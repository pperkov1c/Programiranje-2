#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <math.h>

void unosDuljine(int* m, int* n) {
	do {
		printf("Unesite m:");
		scanf("%d", &*m);
	} while (*m <= 4 || *m > 100);
	do {
		printf("Unesite n:");
		scanf("%d", &*n);
	} while (*n < 3 || *n >= 16);
	printf("m je %d, n je %d\n", *m, *n);
}

TOCKA* zauzimanjeTocaka(const int m) {

	TOCKA* tempZauzimanje = NULL;
	tempZauzimanje = (TOCKA*)malloc(m * sizeof(TOCKA));
	if (tempZauzimanje == NULL) {
		return NULL;
	}
	return tempZauzimanje;
}

CETVEROKUT* zauzimanjeCetverokuta(const int m) {
	CETVEROKUT* tempZauzimanje = NULL;
	tempZauzimanje = (CETVEROKUT*)malloc(m * sizeof(CETVEROKUT));
	if (tempZauzimanje == NULL) {
		return NULL;
	}
	return tempZauzimanje;
}

voidpopunjavanjeKoordinata(TOCKA* pokTocka, const int m) {
	int i, j;
	float donjaGranica = 0;
	float gornjaGranica = 100;
	for (i = 0; i < m; i++) {
		(pokTocka + i)->x = donjaGranica + (float)rand() / RAND_MAX * (gornjaGranica - donjaGranica);
		(pokTocka + i)->y = donjaGranica + (float)rand() / RAND_MAX * (gornjaGranica - donjaGranica);
		printf("%f %f \n", (pokTocka + i)->x, (pokTocka + i)->y);
	}
}
void odabirVrha(TOCKA* pokTocka, CETVEROKUT* pokCetv, const int m, const int n) {
	int dg = 0;
	int gg = m;
	int i;
	int ind1 = 0, ind2 = 0, ind3 = 0, ind4 = 0;

	for (i = 0; i < n; i++) {
		ind1 = dg + (float)rand() / RAND_MAX * (gg - dg);
		(pokCetv + i)->v1 = pokCetv + ind1;


		do {

			ind2 = dg + (float)rand() / RAND_MAX * (gg - dg);
		} while (ind1 == ind2);
		(pokCetv + i)->v2 = pokCetv + ind2;

		do {
			ind3 = dg + (float)rand() / RAND_MAX * (gg - dg);
		} while (ind1 == ind2 && ind1 == ind3);
		(pokCetv + i)->v3 = pokCetv + ind3;

		do {
			ind4 = dg + (float)rand() / RAND_MAX * (gg - dg);
		} while (ind1 == ind2 && ind1 == ind3 && ind1 == ind4);
		(pokCetv + i)->v4 = pokCetv + ind4;
	}
	printf("uspjelo odabiranje\n");
}

double duljinaStranica(float x1, float x2, float y1, float y2) {
	double rez;
	rez = pow((double)x2 - (double)x1, 2) + pow((double)y2 - (double)y1, 2);
	return sqrt(rez);
}

float opsegCetverokuta(CETVEROKUT* pokCetv, const int br) {

	float a, b, c, d, o;
	a = duljinaStranica((pokCetv + br)->v1->x, (pokCetv + br)->v2->x, (pokCetv + br)->v1->y, (pokCetv + br)->v2->y);
	b = duljinaStranica((pokCetv + br)->v2->x, (pokCetv + br)->v3->x, (pokCetv + br)->v2->y, (pokCetv + br)->v3->y);
	c = duljinaStranica((pokCetv + br)->v3->x, (pokCetv + br)->v4->x, (pokCetv + br)->v3->y, (pokCetv + br)->v4->y);
	d = duljinaStranica((pokCetv + br)->v4->x, (pokCetv + br)->v1->x, (pokCetv + br)->v4->y, (pokCetv + br)->v1->y);
	o = a + b + c + d;
	printf("opseg je %f", o);

	return o;
}

