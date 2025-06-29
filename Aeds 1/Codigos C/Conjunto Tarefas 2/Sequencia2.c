#include <stdio.h>
#include <math.h>

int main(){

    double numerador = 1;
    double denominador = 1;
    int i = 0;
    double soma = 0;
    int n = 0;

    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        soma = soma + (numerador / denominador);
        numerador = numerador + 2;
        denominador++;
    }
    printf("%.2lf", soma);
}

