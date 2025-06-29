#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int numReceitas;

    printf("Digite a quantidade de receitas:\n");
    scanf("%d", &numReceitas);

    for (int i = 1; i <= numReceitas; i++) {
        int ingredientes[100];
        int numIngredientes = 0;
        float soma = 0;
        int valor;
        int terminou = 0;

        printf("Digite o %d ingrediente da %d receita:\n", numIngredientes+1, i);
        scanf("%d", &valor);

        while (valor >= 0 && numIngredientes < 100 && !terminou) {
            ingredientes[numIngredientes] = valor;
            soma += valor;
            numIngredientes++;

            if (numIngredientes < 100) {
                printf("Digite o %d ingrediente da %d receita:\n", numIngredientes+1, i);
                scanf("%d", &valor);
            } else {
                terminou = 1;
            }
        }

        if (numIngredientes > 0) {
            printf("Ingredientes da %d receita:", i);
            for (int j = 0; j < numIngredientes; j++) {
                printf("%d", ingredientes[j]);
                if (j < numIngredientes - 1) {
                    printf(",");
                }
            }
            printf(".\n");

            float media = soma / numIngredientes;
            int maiores = 0;
            int menores = 0;

            for (int j = 0; j < numIngredientes; j++) {
                if (ingredientes[j] > media) {
                    maiores++;
                } else if (ingredientes[j] < media) {
                    menores++;
                }
            }

            printf("%d pistas sao maiores que a media %.2f\n", maiores, media);
            printf("%d pistas sao menores que a media %.2f\n", menores, media);
        } else {
            printf("Essa receita nao possui ingredientes!\n");
        }
    }

}
