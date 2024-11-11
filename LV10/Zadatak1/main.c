#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int main() {
	int n;
	int suma;
	FILE* fp;
	fp = fopen("suma.txt", "w");
	if (fp == NULL) {
		printf("Nije moguce otvoriti datoteku. \n");
		return 1;
	}
	printf("Unesite cijeli broj: ");
	scanf("%d", &n);
	suma = sumaBrojeva(n);
	fprintf(fp, "%d", suma);
	fclose(fp);
	printf("Suma znamenaka upisana u datoteku.\n");

	return 0;
}