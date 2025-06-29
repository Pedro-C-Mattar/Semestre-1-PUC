#include <stdio.h>
#include <math.h>

int main(){
    int a1, a2, n, an, r, Sn;

    printf("Digite o valor do 1 termo: \n");
    scanf("%d", &a1);
    printf("Digite o valor do 2 termo: \n");
    scanf("%d", &a2);
    printf("Digite o numero de termos: \n");
    scanf("%d", &n);

    r = a2 - a1;
    an = a1 + (n - 1) * r;
    Sn = (n * (a1 + an)) / 2;

    printf("Soma = %d", Sn);
}

