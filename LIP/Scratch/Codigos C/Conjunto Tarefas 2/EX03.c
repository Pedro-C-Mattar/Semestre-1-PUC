#include <stdio.h>
#include <math.h>

int main(){

    int contador = 1;
    int num = 0;
    int soma = 0;

    printf("Digite um numero:\n");
    scanf("%d", &num);

    while(contador <= num){
        soma = soma + contador;
        contador++;
    }
    printf("A soma de todos os numeros de 1 ate %d = %d", num, soma);
}

