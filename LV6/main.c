#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int main() {
	int izbornikBr;
	int m, n;
	double opseg;

	TOCKA* pokTocka = NULL;
	CETVEROKUT* pokCetv = NULL;

	srand((unsigned)time(NULL));

	while (1) {
		printf("Odaberite jedan broj iz izbornika:\n");
		scanf("%d", &izbornikBr);
		switch (izbornikBr) {
		case 1:
			unosDuljine(&m, &n);
			pokTocka = zauzimanjeTocaka(m);
			if (pokTocka == NULL) {
				return 1;
			}
			pokCetv = zauzimanjeCetverokuta(n);
			if (pokCetv == NULL) {
				return 1;
			}
			break;
		case 2:
			popunjavanjeKoordinata(pokTocka, m);
			odabirVrha(pokTocka, pokCetv, m, n);
			break;
		case 3:
			for (int i = 0; i < m; i++) {
				opseg = opsegCetverokuta(pokCetv, i);
				printf("Opseg je %f", opseg);
			}
			break;
		default:
			return 0;
		}
	}
	free(pokTocka);
	free(pokCetv);

	return 0;

}