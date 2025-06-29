#include <stdio.h>
#include <math.h>

int main() {

    char vendedor[50];
    double salarioFixo, vendas, total;

    fgets(vendedor, sizeof(vendedor), stdin);
    scanf("%lf", &salarioFixo);
    scanf("%lf", &vendas);

    total = salarioFixo + (0.15 * vendas);

    printf("TOTAL = R$ %.2lf", total);

}

