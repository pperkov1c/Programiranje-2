#include<stdio.h>
#include<string.h>

int main() {
	char* dan[7] = { "Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja" };
	int broj;

	do {
		printf("Unesi broj dana u tjednu: \n");
		scanf("%d", &broj);

		if (broj < 1 || broj > 7) {
			printf("Krivi uneseni broj za dan.\n");
		}
	} while (broj < 1 || broj > 7);

	printf("Uneseni broj predstavlja dan %s.\n", *(dan + broj - 1));

	return 0;
}