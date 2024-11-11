#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
union floatBits {
	float f;
	unsigned int bits;
};

int main() {
	float num;
	printf("Upisi realni broj: ");
	scanf("%f", &num);

	union floatBits fb;
	fb.f = num;

	printf("Binarni: ");
	for (int i = 31; i >= 0; i--) {
		printf("%d", (fb.bits >> i) & 1);
	}
	printf("\n");

	return 0;
}