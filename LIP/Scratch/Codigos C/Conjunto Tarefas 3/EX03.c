#include <stdio.h>
#include <math.h>

int main() {
    int i = 0;
    int j = 2;
    int n = 0;
    double num = 0;
    double menor = 9999999;
    double maior = 0;
    double soma = 0;
    double contador = 0;
    double media = 0;

    printf("Digite o numero de series:\n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        printf("Digite o 1 numero da %d serie:\n", i);
        scanf("%lf", &num);
        if(num < menor){
            menor = num;
        }
        if(num > maior){
            maior = num;
        }
        if(num >= 0){
            while(num >= 0){
                soma = soma + num;
                contador = contador + 1;
                printf("Digite o %d numero da %d serie (Flag valor negativo):\n", j, i);
                scanf("%lf", &num);
                if(num >= 0){
                    if(num < menor){
                    menor = num;
                    }
                    if(num > maior){
                    maior = num;
                    }
                    j++;
                }
            }
            media = soma / contador;
            printf("Resultado para a %d serie:\n", i);
            printf("O menor numero encontrado = %.0lf\n", menor);
            printf("O maior numero encontrado = %.0lf\n", maior);
            printf("A media = %.2lf\n", media);
        }
        else{
            printf("Resultado para a %d serie:\n", i);
            printf("Nao existem numeros para essa serie!\n");
        }
        menor = 9999999;
        maior = 0;
        soma = 0;
        contador = 0;
        media = 0;
        j = 2;
    }
}

