#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funkcije.h"

void niz(int* array, int size) {

	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++) {

		array[i] = rand() % 151 - 50;
	}
}

void ispis_niza(int* array, int size) {

	printf("Elementi polja: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int pronalazakNajveceg(int* array, int size) {

	if (size == 1) {
		return array[0];
	}
	int max = pronalazakNajveceg(array, size - 1);
	if (array[size - 1] > max) {
		return array[size - 1];
	}
	else {
		return max;
	}
}

void zapisivanje(int max) {
	FILE* file = fopen("najveci.txt", "w");
	fprintf(file, "%d", max);
	fclose(file);
}
void oslobadanjeNiza(int* array) {
	free(array);
}

void ispisivanjeNajveceg(int max) {
	printf("Najveci element polja: %d\n", max);
}