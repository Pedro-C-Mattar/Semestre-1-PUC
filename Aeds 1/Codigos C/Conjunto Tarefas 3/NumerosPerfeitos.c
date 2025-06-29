#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void numPerfeito(int n) {
    int i = 0;
    int soma = 0;

    for (i = 1; i < n; i++) {
        if (n % i == 0) {
            soma = soma + i;
        }
    }

    if(soma == n){
        printf("%d eh perfeito\n", n);
    }
    else{
        printf("%d nao eh perfeito\n", n);
    }
}

int main() {
    int qtdeTestes = 0;
    int num = 0;
    int i = 0;

    scanf("%d", &qtdeTestes);

    if (qtdeTestes >= 1 && qtdeTestes <= 20){
        for (i = 1; i <= qtdeTestes; i++) {
            scanf("%d", &num);

            if (num >= 1 && num <= 108){

                numPerfeito(num);
            }
            else{
                printf("Valor Invalido");
            }
        }
    }
    else{
        printf("Quantidade Invalida");
    }
}
