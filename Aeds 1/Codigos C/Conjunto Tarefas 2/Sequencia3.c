#include <stdio.h>
#include <math.h>

int main(){

    double numerador = 1;
    double denominador = 1;
    int i = 0;
    double soma = 1;
    int n = 0;
    double fatorial = 1;

    scanf("%d", &n);

    for(denominador = 1; denominador <= n; denominador++){

        for (i = 1; i <= denominador; i++) {
            fatorial = fatorial * i;
        }
        soma = soma + (numerador / fatorial);
        fatorial = 1;
    }
    printf("%.2lf", soma);
}


