#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int numDesafios;
    int numElementos;
    int elementos[100];

    printf("Digite a quantidade de desafios:\n");
    scanf("%d", &numDesafios);

    for (int i = 1; i <= numDesafios; i++) {
        printf("Digite o 1 elemento do %d desafio:\n", i);

        numElementos = 0;
        int continuar = 1;
        while (continuar && numElementos < 100) {
            int temp;
            scanf("%d", &temp);

            if (temp < 0) {
                continuar = 0;
            } else {
                elementos[numElementos] = temp;
                numElementos++;

                if (numElementos < 100) {
                    printf("Digite o %d elemento do %d desafio:\n", numElementos + 1, i);
                }
            }
        }

        if (numElementos > 0) {
            printf("Elementos do %d desafio:", i);
            for (int j = 0; j < numElementos; j++) {
                printf("%d", elementos[j]);
                if (j < numElementos - 1) {
                    printf(",");
                }
            }
            printf(".\n");

            int maisFacil = elementos[0];
            int maisDificil = elementos[0];

            for (int j = 1; j < numElementos; j++) {
                if (elementos[j] < maisFacil) {
                    maisFacil = elementos[j];
                }
                if (elementos[j] > maisDificil) {
                    maisDificil = elementos[j];
                }
            }

            printf("Desafio mais facil:%d\n", maisFacil);
            printf("Desafio mais dificil:%d\n", maisDificil);
        } else {
            printf("Desafio nao possui elementos!\n");
        }
    }
}
