#include <stdio.h>
#include <math.h>

int main(){

    double num = 0;
    double soma = 0;
    double media = 0;
    double contador = 0;

    while(num != -1){
        printf("Digite um numero (-1 para terminar):\n");
        scanf("%lf", &num);
        if(num != -1){
            soma = soma + num;
            contador++;
        }
    }
    media = soma / contador;
    printf("A media dos numeros fornecidos = %.2lf", media);
}




