#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	FILE* fp = NULL;
	const char* primjer = "dat.txt";
	int brojStudenata = 0;

	fp = fopen(primjer, "r");

	if (fp == NULL) {
		printf("Datoteka %s ne postoji na disku!\n", primjer);
	}
	else {
		printf("Datoteka %s postoji na disku!\n", primjer);
		fscanf(fp, "%d", &brojStudenata);
		printf("Broj studenata je %d.\n", brojStudenata);
		fclose(fp);
	}

	FILE* wp = NULL;
	wp = fopen("studenti.txt", "w");
	char ime[40] = { '\0' };
	char prezime[40] = { '\0' };

	if (wp == NULL)
	{
		printf("Datoteka se ne moze kreirati.");
	}
	else {
		for (int i = 0; i < brojStudenata; i++)
		{
			UnosPodataka(ime, prezime);
			zapisUdatoteku(brojStudenata, ime, prezime);
		}

		fclose(wp);
	}

	return 0;
}
