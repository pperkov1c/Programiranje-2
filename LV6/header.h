#ifndef HEADER_H
#define HEADER_H

void unosDuljine(int* m, int* n);

typedef struct {

	float x;
	float y;

}TOCKA;

typedef struct {

	TOCKA* v1;
	TOCKA* v2;
	TOCKA* v3;
	TOCKA* v4;

}CETVEROKUT;

TOCKA* zauzimanjeTocaka(const int m);
CETVEROKUT* zauzimanjeCetverokuta(const int m);
void popunjavanjeKoordinata(TOCKA* pokTocka, const int m);
void odabirVrha(TOCKA* pokTocka, CETVEROKUT* pokCetv, const int m, const int n);
double duljinaStranica(float x1, float x2, float y1, float y2);
float opsegCetverokuta(CETVEROKUT* pokCetv, const int br);

#endif