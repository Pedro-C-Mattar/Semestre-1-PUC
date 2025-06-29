#include <stdio.h>
#include <math.h>

int main() {
    int casos;
    scanf("%d", &casos);

    for (int j = 0; j < casos; j++) {
        double C, i;
        double n;
        scanf("%lf %lf %lf", &C, &i, &n);

        double juros_simples = C * i * n;
        double montante_simples = C + juros_simples;

        double montante_composto = C * pow(1 + i, n);
        double juros_composto = montante_composto - C;

        double diferenca = fabs(montante_simples - montante_composto);

        printf("DIFERENCA DE VALOR = %.2lf\n", diferenca);
        printf("JUROS SIMPLES = %.2lf\n", juros_simples);
        printf("JUROS COMPOSTO = %.2lf\n\n", juros_composto);
    }

    return 0;
}
