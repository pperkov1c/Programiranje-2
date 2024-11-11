#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
struct kompleksni {
	double re;
	double im;
};
int main()
{
	struct kompleksni br1, br2, rez;
	printf("Unesite realni dio prvog broja: ");
	scanf("%lf", &br1.re);
	printf("Unesite imaginarni dio prvog broja: ");
	scanf("%lf", &br1.im);
	printf("Unesite realni dio drugog broja: ");
	scanf("%lf", &br2.re);
	printf("Unesite imaginarni dio drugog broja: ");
	scanf("%lf", &br2.im);

	rez.re = br1.re + br2.re;
	rez.im = br1.im + br2.im;
	printf("Zbroj je jednak: %.2lf + %.2lf*i\n", rez.re, rez.im);

	rez.re = br1.re - br2.re;
	rez.im = br1.im - br2.im;
	printf("Razlika je jednaka: %.2lf + %.2lf*i\n", rez.re, rez.im);

	rez.re = br1.re * br2.re - br1.im * br2.im;
	rez.im = br1.re * br2.re + br1.im * br2.im;
	printf("Produkt je jednak: %.2lf + %.2lf*i\n", rez.re, rez.im);

	double modul_kvadrata = pow(br2.re, 2) + pow(br2.im, 2);
	rez.re = (br1.re * br2.re + br1.im * br2.im);
	rez.im = (br1.re * br2.re - br1.im * br2.im);
	printf("Kolicnik je jednak: %.2lf + %.2lf*i\n", rez.re, rez.im);

	double modul = sqrt(pow(br1.re, 2) + pow(br1.im, 2));
	printf("Modul prvog broja jednak je: %2.lf\n", modul);

	modul = sqrt(pow(br2.re, 2) + pow(br2.im, 2));
	printf("Modul drugog broja jednak je: %2.lf\n", modul);

	return 0;
}
