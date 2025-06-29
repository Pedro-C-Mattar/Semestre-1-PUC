#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int somaDivisores(int matricula) {
    int i = 0;
    int soma = 0;

    for (i = 1; i <= matricula; i++) {
        if (matricula % i == 0) {
            soma = soma + i;
        }
    }

    return soma;
}

int main() {
    int qtdeTestes = 0;
    int num = 0;
    int i = 0;
    int result = 0;

    scanf("%d", &qtdeTestes);

    for (i = 1; i <= qtdeTestes; i++) {
        scanf("%d", &num);
        result = somaDivisores(num);
        printf("%d\n", result);
    }
}
