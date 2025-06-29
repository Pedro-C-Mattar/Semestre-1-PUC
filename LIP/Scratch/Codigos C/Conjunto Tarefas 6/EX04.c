#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int quantidade;
    printf("Digite a quantidade de tesouros:\n");
    scanf("%d", &quantidade);

    int tesouros[100];

    for (int i = 0; i < quantidade; i++) {
        printf("Digite o %d tesouro:\n", i + 1);
        scanf("%d", &tesouros[i]);
    }

    printf("Coordenadas dos tesouros:");
    for (int i = 0; i < quantidade; i++) {
        printf("%d", tesouros[i]);
        if (i < quantidade - 1) {
            printf(",");
        }
    }
    printf(".\n");

    int flag_sair = 0;
    while (!flag_sair) {
        int coordenada;
        printf("Digte a coordenada:\n");
        scanf("%d", &coordenada);

        if (coordenada < 0) {
            flag_sair = 1;
        } else {
            int posicoes[100];
            int contador = 0;

            for (int i = 0; i < quantidade; i++) {
                if (tesouros[i] == coordenada) {
                    posicoes[contador] = i + 1;
                    contador++;
                }
            }

            if (contador > 0) {
                if (contador == 1) {
                    printf("Tesouro %d encontrado na coordenada:", coordenada);
                } else {
                    printf("Tesouro %d encontrado nas coordenadas:", coordenada);
                }

                for (int i = 0; i < contador; i++) {
                    printf("%d", posicoes[i]);
                    if (i < contador - 1) {
                        printf(",");
                    }
                }
                if(contador == 1){
                    printf("\n");
                }
                else{
                    printf(".\n");
                }
            } else {
                printf("Tesouro %d nao encontrado em nenhuma coordenada!\n", coordenada);
            }
        }
    }
}
