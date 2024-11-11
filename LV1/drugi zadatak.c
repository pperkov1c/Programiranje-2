#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main() {
	int binary[8];
	int i, decimal = 0, sign = 1;


	printf("Upišite 8-bitni binarni broj: ");
	for (i = 0; i < 8; i++) {
		scanf("%1d", &binary[i]);
		if (binary[i] != 0 && binary[i] != 1) {
			printf("Krivi unos, molim upišite samo nule i jedinice.\n");
			return 1;
		}
	}


	for (i = 7; i >= 0; i--) {
		decimal += binary[i] * pow(2, 7 - i);
	}


	if (binary[0] == 1) {
		sign = -1;
	}


	printf("Dekadski zapis: %d\n", sign * decimal);

	return 0;
}

