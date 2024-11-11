#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double x;
	double y;
	double z;
} tocka;

int main() {
	int n = 3;

	tocka* tockica = malloc(n * sizeof(tocka));

	for (int i = 0; i < n; i++) {
		printf("Unesite koordinate za tocku %d:\n", i + 1);
		scanf("%lf %lf %lf", &(tockica + i)->x, &(tockica + i)->y, &(tockica + i)->z);
	}

	int najvisa = 0;
	for (int i = 1; i < n; i++) {
		if ((tockica + i)->z > (tockica + najvisa)->z) {
			najvisa = i;
		}
	}

	printf("Najvisa tocka je tocka %d s koordinatama (%.2lf, %.2lf, %.2lf)\n", najvisa + 1, (tockica + najvisa)->x, (tockica + najvisa)->y, (tockica + najvisa)->z);

	free(tockica);

	return 0;
}