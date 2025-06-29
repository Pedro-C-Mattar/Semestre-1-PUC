#include <stdio.h>
#include <math.h>

int main() {

    int cod1, cod2, qtde1, qtde2;
    float valor1, valor2, total;

    scanf("%d %d %f", &cod1, &qtde1, &valor1);
    scanf("%d %d %f", &cod2, &qtde2, &valor2);

    total = (qtde1 * valor1) + (qtde2 * valor2);

    printf("VALOR A PAGAR: R$ %.2f", total);

}
