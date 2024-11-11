#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include "header.h"

void UnosPodataka(char* ime, char* prezime) {
	printf("Unesite ime: ");
	scanf("%19s", ime);
	printf("Unesite prezime: ");
	scanf("%29s", prezime);
}

void zapisUdatoteku(int broj, char* ime, char* prezime) {
	FILE* datoteka = fopen("studenti.txt", "a");
	if (datoteka == NULL) {
		return;
	}

	fprintf(datoteka, "Student broj: %d.\tIme: %s\t Prezime: %s\n", broj, ime, prezime);

}