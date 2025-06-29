#include <stdio.h>
#include <math.h>

int main(){

    int contador = 2;
    int n = 0;
    int termo = 0;
    int a = 1;
    int b = 1;


    while(n <= 2){
        printf("Digite um numero maior que 2:\n");
        scanf("%d", &n);
        if(n <= 2){
            printf("Numero invalido! Deve ser maior que 2.\n");
        }
    }

    printf("A sequencia de Fibonaacci ate o %d termo: %d,%d", n, a, b);

    while(contador < n){
            termo = a + b;
            a = b;
            b = termo;
            contador++;
            printf(",%d", termo);
    }
}

