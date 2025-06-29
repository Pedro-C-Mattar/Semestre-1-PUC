#include <stdio.h>

#define SIZE_V1 10
#define SIZE_V2 5

int main() {
    int v1[SIZE_V1], v2[SIZE_V2];
    int resultado1[SIZE_V2] = {0};
    int resultado2[SIZE_V1];
    int count_impares = 0;

    for (int i = 0; i < SIZE_V1; i++) {
        scanf("%d", &v1[i]);
    }

    for (int i = 0; i < SIZE_V2; i++) {
        scanf("%d", &v2[i]);
    }

    int soma_pares = 0;
    for (int i = 0; i < SIZE_V1; i++) {
        if (v1[i] % 2 == 0) {
            soma_pares += v1[i];
        }
    }

    for (int i = 0; i < SIZE_V2; i++) {
        resultado1[i] = soma_pares + v2[i];
    }

    for (int i = 0; i < SIZE_V1; i++) {
        if (v1[i] % 2 != 0) {
            int count_divisores = 0;
            for (int j = 0; j < SIZE_V2; j++) {
                if (v2[j] != 0 && v1[i] % v2[j] == 0) {
                    count_divisores++;
                }
            }
            resultado2[count_impares] = count_divisores;
            count_impares++;
        }
    }

    printf("Resultado 1: ");
    for (int i = 0; i < SIZE_V2; i++) {
        printf("%d ", resultado1[i]);
    }
    printf("\n");

    printf("Resultado 2: ");
    for (int i = 0; i < count_impares; i++) {
        printf("%d ", resultado2[i]);
    }
    printf("\n");

    return 0;
}
