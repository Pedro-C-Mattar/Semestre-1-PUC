#include <stdio.h>
#include <math.h>

int main() {
    int voltas = 0;
    int placas = 0;
    int total = 0;
    int resultados[9];
    double porcentagem = 0;
    double qtdePlacas = 0;

    scanf("%d %d", &voltas, &placas);

    total = voltas * placas;

    for (int i = 1; i <= 9; i++) {
        porcentagem = i * 10.0 / 100.0;
        qtdePlacas = porcentagem * total;
        resultados[i-1] = ceil(qtdePlacas);
    }

    for (int i = 0; i < 9; i++) {
        printf("%d ", resultados[i]);

    }

    return 0;
}
