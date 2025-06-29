#include <stdio.h>
#include <math.h>

int main(){
    float n1, n2, n3, soma;

    printf("Digite o 1 Valor:\n");
    scanf("%f", &n1);
    printf("Digite o 2 Valor:\n");
    scanf("%f", &n2);
    printf("Digite o 3 Valor:\n");
    scanf("%f", &n3);

    soma = n1 + n2 + n3;

    printf("Soma de %.1f+%.1f+%.1f=%.1f", n1,n2,n3, soma);
}

