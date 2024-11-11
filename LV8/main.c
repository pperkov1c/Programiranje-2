#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "header.h"

int main() {
	int izbor;
	do {
		ispis_izbornika();
		printf("Unesite izbor: ");
		scanf("%d", &izbor);
		switch (izbor) {
		case 1:
			dodaj_clana();
			break;
		case 2:
			citaj_clanove();
			break;
		case 3:
			ispisi_clanove();
			break;
		case 4:
			pronadi_clana();
			break;
		case 5:
			printf("Da li ste sigurni kako zelite zavrsiti program (da/ne).\n");
			char odgovor[4] = { 0 };
			scanf("%s", odgovor);
			if (strcmp(odgovor, "da") == 0) {
				printf("Zavrsetak programa\n");
				return 0;
			}
			else if (strcmp(odgovor, "ne") == 0) {
				continue;
			}
			else {
				printf("Nepoznata opcija. Ponovno Odaberite\n");
				continue;

			}
		default:
			printf("Neispravan izbor\n");
			break;
		}


	} while (1);

	return 0;
}