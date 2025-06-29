#include <stdio.h>

int main() {
    int numPessoas;
    float gastos[12][4];
    float totalMes[12] = {0};
    float totalSemana[4] = {0};
    float totalAnual = 0;
    float perCapita = 0;
    char meses[12][20] = {
        "Janeiro", "Fevereiro", "Marco", "Abril",
        "Maio", "Junho", "Julho", "Agosto",
        "Setembro", "Outubro", "Novembro", "Dezembro"
    };

    scanf("%d", &numPessoas);

    for (int i = 0; i < 12; i++) {
        scanf("%f %f %f %f", &gastos[i][0], &gastos[i][1], &gastos[i][2],&gastos[i][3]);
    }

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 4; j++) {
            totalMes[i] += gastos[i][j];
            totalSemana[j] += gastos[i][j];
        }
        totalAnual += totalMes[i];
    }

    perCapita = totalAnual / numPessoas;

    printf("Total gasto por mes:\n");
    for (int i = 0; i < 12; i++) {
        printf("%s: R$ %.2f\n", meses[i], totalMes[i]);
    }

    printf("Total gasto por semana (ao longo do ano):\n");
    for (int j = 0; j < 4; j++) {
        printf("Semana %d: R$ %.2f\n", j + 1, totalSemana[j]);
    }

    printf("Total gasto pela familia no ano: R$ %.2f\n", totalAnual);
    printf("Gasto anual per capita: R$ %.2f\n", perCapita);

    return 0;
}
