#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int numeros[20];
    int pares[20];
    int impares[20];
    int countPares = 0, countImpares = 0;

    printf("Digite os 20 elementos:\n");

    for (int i = 0; i < 20; i++) {
        printf("Digite o %d representante: \n", i+1);
        scanf("%d", &numeros[i]);

        if (numeros[i] % 2 == 0) {
            pares[countPares] = numeros[i];
            countPares++;
        } else {
            impares[countImpares] = numeros[i];
            countImpares++;
        }
    }

    printf("Representantes dos clas:");
    for (int i = 0; i < 20; i++) {
        printf("%d", numeros[i]);
        if (i < 19) printf(",");
    }
    printf(".\n");

    printf("Representante   CLA Par\n");
    for (int i = 0; i < countPares; i++) {
        printf("%6d         PAR\n", pares[i]);
    }

    printf("Representante   CLA Impar\n");
    for (int i = 0; i < countImpares; i++) {
        printf("%6d         IMPAR\n", impares[i]);
    }

}
