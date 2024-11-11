#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

#define N 500

int main() {
	int* polje[N];
	int broj;

	srand((unsigned)time(NULL));
	upisivanjeBrojeva();
	citanjeBrojeva(&polje);
	broj = upisivanjeTrazenogBroja();
	sekvencijalnoPretrazivanje(&polje, broj);
	return 0;
}