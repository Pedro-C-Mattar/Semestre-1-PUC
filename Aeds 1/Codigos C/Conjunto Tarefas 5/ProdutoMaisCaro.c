#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d\n", &N);

    char linha[201];
    char nome[101];
    char nomeMaisCaro[101] = "";
    char nomeMaisBarato[101] = "";
    float preco, soma = 0.0;
    float maiorPreco = -1.0;
    float menorPreco = 1e9;

    for (int i = 0; i < N; i++) {
        fgets(linha, sizeof(linha), stdin);
        linha[strcspn(linha, "\n")] = '\0';

        int j = 0;
        while (linha[j] != ';' && linha[j] != '\0') {
            nome[j] = linha[j];
            j++;
        }
        nome[j] = '\0';
        j++;

        char valorStr[20];
        int k = 0;
        while (linha[j] != ';' && linha[j] != '\0') {
            valorStr[k++] = linha[j++];
        }
        valorStr[k] = '\0';

        preco = atof(valorStr);
        soma += preco;

        if (preco > maiorPreco) {
            maiorPreco = preco;
            strcpy(nomeMaisCaro, nome);
        }

        if (preco < menorPreco) {
            menorPreco = preco;
            strcpy(nomeMaisBarato, nome);
        }
    }

    printf("%.2f\n", soma / N);
    printf("%s\n", nomeMaisCaro);
    printf("%s\n", nomeMaisBarato);

    return 0;
}
