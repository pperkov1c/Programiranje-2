#define _CRT_SECURE_NO_WARNINGS
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE* datoteka = fopen("studenti.txt", "r");
	if (datoteka == NULL) {
		printf("Nemogu?e otvoriti datoteku studenti.txt.\n");
		return 1;
	}

	STUDENT* head = NULL;

	char ime[50];
	char prezime[50];
	int id;

	while (fscanf(datoteka, "%s %s %d", ime, prezime, &id) == 3) {
		dodajStudentaNaPocetak(&head, ime, prezime, id);
	}

	fclose(datoteka);

	ispisiPopis(head);
	int broj = brojElemenata(head);
	printf("Broj elemenata: %d\n\n", broj);

	int zadaniID;
	printf("Unesite ID studenta kojeg zelite izbrisati: ");


	scanf("%d", &zadaniID);

	obrisiStudenta(&head, zadaniID);

	ispisiPopis(head);
	broj = brojElemenata(head);
	printf("Broj elemenata nakon brisanja: %d\n\n", broj);

	obrisiPopis(&head);

	return 0;
}