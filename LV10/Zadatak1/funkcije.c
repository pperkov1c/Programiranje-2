#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int sumaBrojeva(int n) {
	if (n == 0) {
		return 0;
	}
	else {
		return(n % 10) + sumaBrojeva(n / 10);
	}
}