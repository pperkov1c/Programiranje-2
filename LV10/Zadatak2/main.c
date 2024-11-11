#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funkcije.h"

int main() {

	int n;

	printf("Unesite broj elemenata polja [1-20]\n");
	scanf("%d", &n);

	if (n <= 0 || n > 20) {
		printf("Neispravan unos broja elemenata polja.\n");
		return 1;

	}

	int* arr = malloc(n * sizeof(int));
	niz(arr, n);
	ispis_niza(arr, n);
	int max = pronalazakNajveceg(arr, n);
	zapisivanje(max);
	ispisivanjeNajveceg(max);
	oslobadanjeNiza(arr);

	return 0;
}