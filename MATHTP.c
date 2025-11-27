#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c, A, B;
    int r, q, i = 1, N;

    // Coefficients de Bezout initiaux
    int x0 = 1, x1 = 0, y0 = 0, y1 = 1;

    // ========== PARTIE 1 : Algorithme d'Euclide etendu ==========
    printf("========== ALGORITHME D'EUCLIDE ETENDU ==========\n\n");

    // Lire a et b avec validation
    printf("Entrer deux entiers positifs a et b : ");
    scanf("%d%d", &a, &b);

    // Validation des entrees
    if (a <= 0 || b <= 0) {
        printf("Erreur : a et b doivent etre positifs.\n");
        return 1;
    }

    A = a;  // Sauvegarde pour affichage final
    B = b;

    // Lire c
    printf("Entrer c tel que ax + by = c : ");
    scanf("%d", &c);

    printf("\n--- Etapes de l'algorithme ---\n");
    printf("Etape %d : a=%d, b=%d, x=%d, y=%d\n", i, a, b, x0, y0);

    // Algorithme d'Euclide etendu
    while (b != 0) {
        r = a % b;
        q = a / b;

        printf("Etape %d : a=%d, b=%d, quotient=%d, reste=%d, x=%d, y=%d\n",
               i + 1, a, b, q, r, x1, y1);

        // Mise a jour des valeurs
        a = b;
        b = r;

        // Calcul des nouveaux coefficients de Bezout
        int x2 = x0 - q * x1;
        int y2 = y0 - q * y1;

        x0 = x1;
        x1 = x2;
        y0 = y1;
        y1 = y2;

        i++;
    }

    int d = a; // PGCD final

    // ========== RESULTATS ==========
    printf("\n--- Resultats ---\n");
    printf("PGCD(%d, %d) = %d\n", A, B, d);

    // Verification si A et B sont premiers entre eux
    if (d == 1) {
        printf("=> %d et %d sont premiers entre eux.\n", A, B);
    }

    printf("Coefficients de Bezout : x0 = %d, y0 = %d\n", x0, y0);
    printf("Verification : %d * %d + %d * %d = %d\n\n", A, x0, B, y0, A*x0 + B*y0);

    // ========== EQUATION DIOPHANTIENNE ==========
    printf("--- Equation %d*x + %d*y = %d ---\n", A, B, c);

    // Verification de l'existence de solutions
    if (c % d != 0) {
        printf("[X] Il n'existe pas de solution entiere.\n");
        printf("    (car %d ne divise pas %d)\n", d, c);
    } else {
        printf("[OK] Il existe des solutions entieres.\n");

        // Solution particuliere
        int k = c / d;
        int x = x0 * k;
        int y = y0 * k;

        printf("\nSolution particuliere : x = %d, y = %d\n", x, y);
        printf("Verification : %d * %d + %d * %d = %d\n", A, x, B, y, A*x + B*y);

        // Solution generale
        printf("\nSolution generale :\n");
        printf("  x = %d + %d*k\n", x, B/d);
        printf("  y = %d - %d*k\n", y, A/d);
        printf("  ou k est un entier quelconque (k dans Z)\n");

        // Exemples de solutions
        printf("\nExemples de solutions :\n");
        for (int k_val = -2; k_val <= 2; k_val++) {
            int x_k = x + (B/d) * k_val;
            int y_k = y - (A/d) * k_val;
            printf("  k=%2d : x=%4d, y=%4d\n", k_val, x_k, y_k);
        }
    }

    // ========== PARTIE 2 : Nombres premiers ==========
    printf("\n\n========== NOMBRES PREMIERS ==========\n\n");
    printf("Entrer un entier N : ");
    scanf("%d", &N);

    if (N <= 2) {
        printf("Aucun nombre premier inferieur a %d.\n", N);
    } else {
        printf("Nombres premiers inferieurs a %d :\n", N);

        int compte = 0;
        for (int n = 2; n < N; n++) {
            int premier = 1;

            // Test de primalite
            for (int j = 2; j * j <= n; j++) {
                if (n % j == 0) {
                    premier = 0;
                    break;
                }
            }

            if (premier) {
                printf("%d ", n);
                compte++;

                // Retour a la ligne tous les 15 nombres
                if (compte % 15 == 0) {
                    printf("\n");
                }
            }
        }

        printf("\n\nTotal : %d nombre(s) premier(s) trouve(s).\n", compte);
    }

    return 0;
}
