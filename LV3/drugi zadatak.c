#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	char ime[30];
	char prezime[30];
	char oib[12];
	float placa;
	int danRodenja;
	int mjesecRodenja;
	int godinaRodenja;
} Programer;

int main() {
	Programer programeri[15];
	int n;
	do {
		printf("Unesite broj programera: ");
		scanf("%d", &n);
	} while (n < 1 || n > 15);

	for (int i = 0; i < n; i++) {
		printf("Unesite podatke za programera %d:\n", i + 1);
		printf("Ime: ");
		scanf("%s", programeri[i].ime);
		printf("Prezime: ");
		scanf("%s", programeri[i].prezime);
		printf("OIB: ");
		scanf("%s", programeri[i].oib);
		printf("Placa: ");
		scanf("%f", &programeri[i].placa);
		printf("Datum rodenja: ");
		scanf("%d.%d.%d", &programeri[i].danRodenja, &programeri[i].mjesecRodenja, &programeri[i].godinaRodenja);
	}

	int indeks_najbolje_place = 0;
	for (int i = 1; i < n; i++) {
		if (programeri[i].placa > programeri[indeks_najbolje_place].placa) {
			indeks_najbolje_place = i;
		}
	}

	printf("Programer s najboljom i najvecom placom:\n");
	printf("Ime: %s\n", programeri[indeks_najbolje_place].ime);
	printf("Prezime: %s\n", programeri[indeks_najbolje_place].prezime);
	printf("OIB: %s\n", programeri[indeks_najbolje_place].oib);
	printf("Placa: %.2f\n", programeri[indeks_najbolje_place].placa);
	printf("Datum rodenja: %02d.%02d.%04d\n", programeri[indeks_najbolje_place].danRodenja,
		programeri[indeks_najbolje_place].mjesecRodenja, programeri[indeks_najbolje_place].godinaRodenja);

	return 0;
}

