#include <stdio.h>
#include <math.h>

int main(){

    int num = 0;
    int soma = 0;

    while(num != -1){
        printf("Digite um numero (-1) para ternimar:\n");
        scanf("%d", &num);
        if(num != -1){
            soma = soma + num;
        }
    }
    printf("A soma dos numeros fornecidos = %d", soma);
}



