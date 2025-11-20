#include <stdio.h>

int main() {
    int i, j, estPremier;

    printf("Vérification des nombres premiers de 1 à 25:\n\n");

    for (i = 1; i <= 25; i++) {
        estPremier = 1; // On suppose que le nombre est premier

        if (i < 2) {
            estPremier = 0; // 0 et 1 ne sont pas premiers
} else {
            for (j = 2; j < i; j++) {
                if (i % j == 0) {
                    estPremier = 0; // i est divisible par j → pas premier
                    break;
}
}
}

        if (estPremier)
            printf("%d est un nombre premier.\n", i);
        else
            printf("%d n'est pas un nombre premier.\n", i);
}

    return 0;
}