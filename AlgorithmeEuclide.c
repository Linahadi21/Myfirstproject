#include <stdio.h>

int main() {
    int a, b, reste;

    printf("Entrez deux entiers positifs : ");
    scanf("%d %d", &a, &b);

    int a_initial = a, b_initial = b; // pour afficher les étapes plus tard

    printf("\nÉtapes de calcul :\n");

    while (b != 0) {
        reste = a % b;
        printf("%d = %d * (%d) + %d\n", a, b, a / b, reste);
        a = b;
        b = reste;
    }

    printf("\nLe PGCD(%d, %d) = %d\n", a_initial, b_initial, a);

    return 0;
}
