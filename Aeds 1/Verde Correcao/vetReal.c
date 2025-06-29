#include <stdio.h>

int main() {
    int n, negativos = 0;
    float soma_positivos = 0.0f;

    scanf("%d", &n);

    float numeros[n];

    for (int i = 0; i < n; i++) {
        scanf("%f", &numeros[i]);
    }

    for (int i = 0; i < n; i++) {
        if (numeros[i] < 0) {
            negativos++;
        } else {
            soma_positivos += numeros[i];
        }
    }

    printf("%d %.1f\n", negativos, soma_positivos);

    return 0;
}
