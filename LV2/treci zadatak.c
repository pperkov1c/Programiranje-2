#include<stdio.h>
int main() {
	char* mjeseci[12] = { "Sijecanj", "Veljaca", "Ozujak", "Travanj", "Svibanj", "Lipanj",
	"Srpanj", "Kolovoz", "Rujan", "Listopad", "Studeni", "Prosinac" };

	int n;

	do {
		printf("Unesite broj mjeseca: ");
		scanf("%d", &n);

		if (n < 1 || n > 12) {
			printf("Krivo uneseni broj za mjesec!\n");
		}
	} while (n < 1 || n > 12);

	printf("Trazeni mjesec: %s\n", *(mjeseci + n - 1));

	return 0;
}