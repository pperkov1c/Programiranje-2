#ifndef HEADER_H
#define HEADER_H

#define MAX_FILMOVA 4

typedef struct clan {
	int id;
	char ime[50];
	char prezime[50];
	char adresa[100];
	char mobitel[20];
	int broj_posudjenih;

}CLAN;

void ispis_izbornika();
void dodaj_clana();
void citaj_clanove();
void ispisi_clanove();
void pronadi_clana();




#endif