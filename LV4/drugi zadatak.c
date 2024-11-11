#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char ime[50];
    double cijena;
    int kolicina;
}artikl;

int main()
{
    int n;
    printf("Unesite broj artikala: ");
    scanf("%d", &n);

    artikl* polje_artikala = malloc(n * sizeof(artikl));

    for (int i = 0; i < n; i++) {
        printf("Unesite ime, cijenu i kolicinu za artikal %d:\n", i + 1);
        scanf("%s %lf %d", &(polje_artikala + i)->ime, &(polje_artikala + i)->cijena, &(polje_artikala + i)->kolicina);
    }


    artikl* max = &polje_artikala[0];
    for (int i = 1; i < n; i++) {
        if ((polje_artikala + i)->cijena > max->cijena) {
            max = polje_artikala + i;
        }
    }


    printf("Najskuplji artikal je %s, kosta %.2lf eura i ima %d komada.\n", max->ime, max->cijena, max->kolicina);

    free(polje_artikala);
    return 0;
}