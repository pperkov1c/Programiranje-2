#define _CRT_SECURE_NO_WARNINGS
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dodajStudentaNaPocetak(STUDENT** head, char* ime, char* prezime, int id) {
	STUDENT* noviStudent = (STUDENT*)malloc(sizeof(STUDENT));
	noviStudent->ime = (char*)malloc((strlen(ime) + 1) * sizeof(char));
	strcpy(noviStudent->ime, ime);
	noviStudent->prezime = (char*)malloc((strlen(prezime) + 1) * sizeof(char));
	strcpy(noviStudent->prezime, prezime);
	noviStudent->id = id;

	noviStudent->next = *head;
	*head = noviStudent;
}

void ispisiPopis(STUDENT* head) {
	printf("Popis studenata:\n");
	STUDENT* trenutni = head;
	while (trenutni != NULL) {
		printf("ID: %d, Ime: %s, Prezime: %s\n", trenutni->id, trenutni->ime, trenutni->prezime);
		trenutni = trenutni->next;
	}
	printf("\n");
}

int brojElemenata(STUDENT* head) {
	int brojac = 0;
	STUDENT* current = head;
	while (current != NULL) {
		brojac++;
		current = current->next;
	}
	return brojac;
}

void obrisiStudenta(STUDENT** head, int id) {
	STUDENT* trenutni = *head;
	STUDENT* prethodni = NULL;

	while (trenutni != NULL) {
		if (trenutni->id == id) {
			if (prethodni == NULL) {
				*head = trenutni->next;
			}
			else {
				prethodni->next = trenutni->next;
			}
			free(trenutni->ime);
			free(trenutni->prezime);
			free(trenutni);
			break;
		}
		prethodni = trenutni;
		trenutni = trenutni->next;
	}
}

void obrisiPopis(STUDENT** head) {
	STUDENT* current = *head;
	STUDENT* sljedeci;

	while (current != NULL) {
		sljedeci = current->next;
		free(current->ime);
		free(current->prezime);
		free(current);
		current = sljedeci;
	}

	*head = NULL;
}