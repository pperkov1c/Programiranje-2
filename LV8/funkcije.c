#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "header.h"


void ispis_izbornika() {
	printf("Izbornik:\n");
	printf("1.Dodavanje novih clanova\n");
	printf("2.Citanje clanova iz datoteke\n");
	printf("3.Ispisivanje podataka o svim clanovima\n");
	printf("4.Pretrazi clana po ID\n");
	printf("5.Izlazak iz programa\n");
}

int generiraj_novi_id() {
	FILE* f = fopen("clanovi.bin", "rb");
	if (f == NULL) {
		return 1;
	}
	CLAN c;
	int max_id = 0;
	while (fread(&c, sizeof(c), 1, f) == 1) {
		if (c.id > max_id) {
			max_id = c.id;
		}
	}
	fclose(f);

	return max_id + 1;
}

void dodaj_clana() {
	FILE* f = fopen("clanovi.bin", "ab");
	if (f == NULL) {
		printf("Ne mogu otvoriti datoteku\n");
		return;
	}
	CLAN c;
	c.id = generiraj_novi_id();
	printf("Unesite ime: ");
	scanf("%s", c.ime);
	printf("Unesite prezime: ");
	scanf("%s", c.prezime);
	printf("Unesite adresu: ");
	getchar();
	fgets(c.adresa, sizeof(c.adresa), stdin);
	printf("Unesite broj mobitela: ");
	scanf("%s", c.mobitel);
	c.broj_posudjenih = 0;
	fwrite(&c, sizeof(c), 1, f);
	fclose(f);
	printf("Clan dodan u bazu podataka.\n");
}


void citaj_clanove() {
	FILE* f = fopen("clanovi.bin", "rb");
	if (f == NULL) {

		printf("Ne mogu otvoriti dadoteku\n");
		return;
	}
	CLAN c;
	while (fread(&c, sizeof(c), 1, f)) {
		printf("%d %s %s %s %s %d\n", c.id, c.ime, c.prezime, c.adresa, c.mobitel, c.broj_posudjenih);

	}

	fclose(f);

}
void ispisi_clanove() {
	FILE* f = fopen("clanovi.bin", "rb");
	if (f == NULL) {
		printf("Ne mogu otvoriti dadoteku\n");
		return;
	}
	CLAN c;

	int broj_clanova = 0;
	int ukupno_posudjenih = 0;
	while (fread(&c, sizeof(c), 1, f)) {
		printf("ID:%d Ime:%s Prezime:%s Adresa:%s Broj mobitela:%s Broj posudenih filmova:%d\n", c.id, c.ime, c.prezime, c.adresa, c.mobitel, c.broj_posudjenih);
		broj_clanova++;
		ukupno_posudjenih += c.broj_posudjenih;
	}
	printf("Ukupno clanova: %d\n", broj_clanova);
	printf("Ukupno posudjenih filmova: %d\n", ukupno_posudjenih);
	fclose(f);
}
void pronadi_clana() {

	int id;
	printf("Unesite ID clana kojeg zelite pronaci: ");
	scanf("%d", &id);

	FILE* f = fopen("clanovi.bin", "rb");
	if (f == NULL) {

		printf("Ne mogu otvoriti dadoteku\n");
		return;
	}
	CLAN c;
	int pronaden = 0;
	while (fread(&c, sizeof(c), 1, f)) {
		if (c.id == id) {
			printf("Pronaden clan:\n");
			printf("ID: %d\nIme: %s\nPrezime: %s\nAdresa: %s\nMobitel: %s\nBroj posudjenih filmova: %d\n", c.id, c.ime, c.prezime, c.adresa, c.mobitel, c.broj_posudjenih);
			pronaden = 1;
			break;
		}
	}

	if (!pronaden) {
		printf("Nema clana s ID-om %d\n", id);
	}
	fclose(f);
}