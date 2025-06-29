#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void juros(double val, double tax, int temp) {

    double montanteSimples = 0;
    double jurosSimples = 0;
    double montanteComposto = 0;
    double jurosComposto = 0;
    double diferenca = 0;

    jurosSimples = val * tax * temp;
    montanteSimples = val + jurosSimples;

    montanteComposto = val * pow(1 + tax, temp);
    jurosComposto = montanteComposto - val;

    diferenca = fabs(montanteSimples - montanteComposto);

    printf("DIFERENCA DE VALOR = %.2lf\n", diferenca);
    printf("JUROS SIMPLES = %.2lf\n", jurosSimples);
    printf("JUROS COMPOSTO = %.2lf\n", jurosComposto);

}

int main() {
    int qtdeTestes = 0;
    int i = 0;
    double valor = 0;
    double taxa = 0;
    int tempo = 0;

    scanf("%d", &qtdeTestes);

    for (i = 1; i <= qtdeTestes; i++) {
        scanf("%lf", &valor);
        scanf("%lf", &taxa);
        scanf("%d", &tempo);

        juros(valor, taxa, tempo);
    }
}
