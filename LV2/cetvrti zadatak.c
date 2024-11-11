#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	char* mjesec[12] = { "Sijecanj", "Veljaca", "Ozujak", "Travanj", "Svibanj", "Lipanj", "Srpanj", "Kolovoz", "Rujan", "Listopad", "Studeni", "Prosinac" };
	int broj;

	do {
		printf("Unesi broj mjeseca: \n");
		scanf("%d", &broj);

		if (broj < 1 || broj > 12) {
			printf("Krivo uneseni broj za mjesec.\n");
		}
	} while (broj < 1 || broj > 12);

	printf("Uneseni broj predstavlja mjesec %s\n", *(mjesec + broj - 1));

	printf("\n");

	float maks = 0.0;
	int maks_index = 0;
	int suma = 0;
	int brojac = 0;
	for (int i = 0; i < 12; i++) {
		char* ime_mjeseca = *(mjesec + i);
		for (int j = 0; *(ime_mjeseca + j) != '\0'; j++) {
			suma += (int)*(ime_mjeseca + j);
			brojac++;
		}
		float avr = (float)suma / brojac;
		if (avr > maks) {
			maks = avr;
			maks_index = i;
		}
	}
	char* maks_ime = *(mjesec + maks_index);
	int maks_ime_len = strlen(maks_ime);

	printf("Mjesec s najvecom srednjom vrijednosti znakova u imenu: %s\n", maks_ime);

	printf("Ime mjeseca naopako: \n");
	for (int i = maks_ime_len - 1; i >= 0; i--) {
		printf("%c", *(maks_ime + i));
	}
	printf("\n");
	return 0;
}

