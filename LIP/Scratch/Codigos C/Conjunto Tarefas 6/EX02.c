#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int numConjuntos;

    printf("Digite a quantidade de informacoes:\n");
    scanf("%d", &numConjuntos);

    for (int i = 1; i <= numConjuntos; i++) {
        float valores[100];
        int numPistas = 0;
        float soma = 0;
        float media;
        int maioresQueMedia = 0;
        int flagNegativo = 0;

        printf("Digite a 1 pista da %d informacao misteriosa:\n", i);
        scanf("%f", &valores[0]);

        if (valores[0] < 0) {
            flagNegativo = 1;
        }

        if (!flagNegativo) {
            numPistas = 1;
            soma = valores[0];

            for (int j = 1; j < 100; j++) {
                printf("Digite a %d pista da %d informacao misteriosa:\n", j+1, i);
                scanf("%f", &valores[j]);

                if (valores[j] < 0) {
                    flagNegativo = 1;
                    j = 100;
                } else {
                    numPistas++;
                    soma += valores[j];
                }
            }
        }

        if (flagNegativo && numPistas == 0) {
            printf("Essa informacao nao possui pistas!\n");
        } else {
            media = soma / numPistas;

            printf("Pistas da %d informacao misteriosa:", i);
            for (int j = 0; j < numPistas; j++) {
                printf("%.0f", valores[j]);
                if (j < numPistas - 1) {
                    printf(",");
                }
            }
            printf(".\n");

            for (int j = 0; j < numPistas; j++) {
                if (valores[j] > media) {
                    maioresQueMedia++;
                }
            }

            printf("%d pistas sao maiores que a media %.2f\n", maioresQueMedia, media);
        }
    }

}
