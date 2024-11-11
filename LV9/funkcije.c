#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

#define N 500



int randomBrojevi() {

	int dg = 0;
	int gg = 1000;
	int temp;

	temp = dg + (float)rand() / RAND_MAX * (gg - dg);

	return temp;
}

void upisivanjeBrojeva() {

	FILE* fp = NULL;
	int i;

	fp = fopen("dat.txt", "w");
	if (fp == NULL)
	{
		printf("Datoteka se ne moze kreirati.\n");
		exit(-1);
	}
	else {
		for (i = 0; i < N; i++) {
			fprintf(fp, "%d ", randomBrojevi());
		}
		fclose(fp);
	}
}



void citanjeBrojeva(int* polje) {

	FILE* fp = NULL;
	int i;

	fp = fopen("dat.txt", "r");
	if (fp == NULL) {
		printf("Datoteka ne postoji na disku.\n");
		exit(-1);
	}
	else {
		for (i = 0; i < N; i++) {
			fscanf(fp, "%d", (polje + i));
			printf("%d ", *(polje + i));
		}
		fclose(fp);
	}
}

int upisivanjeTrazenogBroja() {
	int temp;
	printf("\n");
	do {
		printf("Unesite broj od 0 do 1000:");
		scanf("%d", &temp);
	} while (temp < 0 || temp > 1000);

	return temp;

}

void sekvencijalnoPretrazivanje(int* polje, int m) {

	int f = 0;
	for (int i = 0; i < N; i++) {
		if (*(polje + i) == m) {
			printf("Broj %d je pronaden u %d koraka\n", m, i + 1);
			f = 1;
		}
	}
	if (f == 0) {
		printf("Broj %d nije pronaden.", m);
	}
}