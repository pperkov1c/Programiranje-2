#ifndef HEADER_H
#define HEADER_H
typedef struct student {
	char* ime;
	char* prezime;
	int id;
	struct student* next;
} STUDENT;

void dodajStudentaNaPocetak(STUDENT** head, char* ime, char* prezime, int id);
void ispisiPopis(STUDENT* head);
int brojElemenata(STUDENT* head);
void obrisiStudenta(STUDENT** head, int id);
void obrisiPopis(STUDENT** head);
#endif