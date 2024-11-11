#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
	int polje[32];
	int i;
	float broj = 0;

	srand((unsigned)time(NULL));
	for (i = 0; i < 32; i++) {
		polje[i] = rand() % 2;
	}

	for (i = 0; i < 32; i++) {
		broj += polje[i] * pow(2, -(i + 1));
	}

	printf("Binarni ekvivalent: ");
	for (i = 0; i < 32; i++) {
		printf("%d", polje[i]);
	}
	printf("\nDekadski ekvivalent: %f\n", broj);

	return 0;
}
