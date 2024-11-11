#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define VEL_POLJA 32

int main()
{
	int bin[VEL_POLJA];
	int i, dek;

	srand(time(0));

	for (i = 0; i < VEL_POLJA; i++) {
		bin[i] = rand() % 2;
	}
	dek = 0;
	for (i = 0; i < VEL_POLJA; i++) {
		dek += bin[i] * pow(2, VEL_POLJA - i - 1);
	}
	printf("Binarni zapis: ");
	for (i = 0; i < VEL_POLJA; i++) {
		printf("%d", bin[i]);
	}
	printf("\nDekadski zapis: %d\n", dek);
	return 0;
}
