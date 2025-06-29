#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int idade = 0;
    int gostou = 0;
    char genero;
    double contador = 0;
    double naoGostou = 0;
    int mascGostou = 0;
    int femiGostou = 0;
    int maiorMascGostou = 0;
    int menorFemiNaoGostou = 99999;
    double percentNaoGostou = 0;

    while (idade >= 0) {
        scanf("%d %c %d", &idade, &genero, &gostou);

        if(idade >= 0){


            if (gostou == 0) {
                naoGostou = naoGostou + 1;
            }
            if (gostou == 1 && genero == 'M') {
                mascGostou ++;
            }
            if (gostou == 1 && genero == 'F') {
                femiGostou ++;
            }
            if (gostou == 1 && genero == 'M' && idade > maiorMascGostou) {
                maiorMascGostou = idade;
            }
            if(gostou == 0 && genero == 'F' && idade < menorFemiNaoGostou) {
                menorFemiNaoGostou = idade;
            }
        }

        contador = contador + 1;
    }

    percentNaoGostou = (naoGostou / contador) * 100;

    printf("Masculino: %d\n", mascGostou);
    printf("Feminino: %d\n", femiGostou);
    printf("%d anos\n", maiorMascGostou);
    printf("%d anos\n", menorFemiNaoGostou);
    printf("%.2lf%%\n", percentNaoGostou);

}
