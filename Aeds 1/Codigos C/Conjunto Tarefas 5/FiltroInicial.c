#include <stdio.h>

char toMinusculo(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

int main() {
    int N;
    char letraDesejada;
    scanf("%d\n", &N);
    scanf("%c\n", &letraDesejada);

    letraDesejada = toMinusculo(letraDesejada);

    int contador = 0;

    for (int i = 0; i < N; i++) {
        char nome[51];
        int j = 0;
        char c;
        while ((c = getchar()) != '\n' && c != EOF) {
            if (j < 50) {
                nome[j++] = c;
            }
        }
        nome[j] = '\0';

        if (toMinusculo(nome[0]) == letraDesejada) {
            contador++;
        }
    }

    printf("%d\n", contador);
    return 0;
}
