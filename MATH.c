#include <stdio.h>

int main() {
    int a, b, x, y, pgcd, ppcm;
    int i, j, estPremier;

    /* ======= 1) PGCD ======= */
    printf("Entrer deux entiers pour calculer le PGCD : ");
    scanf("%d %d", &a, &b);

    x = a;
    y = b;

    while (x != y) {
        if (x > y)
            x = x - y;
        else
            y = y - x;
    }

    pgcd = x;
    printf("PGCD(%d, %d) = %d\n\n", a, b, pgcd);

    /* ======= 2) PPCM ======= */
    ppcm = (a * b) / pgcd;
    printf("PPCM(%d, %d) = %d\n\n", a, b, ppcm);

    /* ======= 3) Nombres premiers de 1 à 100 ======= */
    printf("Nombres premiers de 1 a 100 :\n");

    for (i = 2; i <= 100; i++) {
        estPremier = 1;

        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                estPremier = 0;
                break;
            }
        }

        if (estPremier == 1) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}
