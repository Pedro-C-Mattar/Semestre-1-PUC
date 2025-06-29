#include <stdio.h>
#include <math.h>

int main(){

    int contador = 1;
    int num = 0;
    int fatorial = 1;

    printf("Digite um numero:\n");
    scanf("%d", &num);

    while(contador <= num){
        fatorial = fatorial * contador;
        contador++;
    }
    printf("O fatorial de %d = %d", num, fatorial);
}


