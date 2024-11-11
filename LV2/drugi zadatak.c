#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int suglasnik(char* str) {
	int brojac = 0;
	char s;

	for (int i = 0; *(str + i) != '\0'; i++) {
		s = *(str + i);
		if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U') {
			brojac++;
		}
	}

	return brojac;
}

int main() {
	char* dan[7] = { "ponedjeljak", "utorak", "srijeda", "cetvrtak", "petak", "subota", "nedjelja" };


	int broj;

	do {
		printf("Unesi broj dana u tjednu: \n");
		scanf("%d", &broj);

		if (broj < 1 || broj > 7) {
			printf("Krivi uneseni broj za dan.\n");
		}
	} while (broj < 1 || broj > 7);

	printf("Uneseni broj predstavlja dan %s.\n", *(dan + broj - 1));

	printf("\n");


	int broj_suglasnika[7] = { 0 };
	int max_suglasnika = 0;
	int dan_s_najvise_suglasnika;

	for (int i = 0; i < 7; i++) {
		broj_suglasnika[i] = suglasnik(*(dan + i));

		if (broj_suglasnika[i] > max_suglasnika) {
			max_suglasnika = broj_suglasnika[i];
			dan_s_najvise_suglasnika = i;
		}
	}

	printf("Dan s najvise suglasnika je %s.\n", *(dan + dan_s_najvise_suglasnika));

	char* najveci_dan = *(dan + dan_s_najvise_suglasnika);
	int dan_len = strlen(najveci_dan);

	printf("Dan s najvise suglasnika zapisan naopako: \n");
	for (int i = dan_len - 1; i >= 0; i--) {
		printf("%c", *(najveci_dan + i));
	}
	printf("\n");
	return 0;
}

