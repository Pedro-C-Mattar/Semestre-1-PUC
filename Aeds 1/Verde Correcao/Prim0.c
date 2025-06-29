#include <stdio.h>
#include <stdbool.h>

bool ehPrimo(int num) {
    if (num <= 1) {
        return false;
    }
    if (num == 2) {
        return true;
    }
    if (num % 2 == 0) {
        return false;
    }
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int numero;

    scanf("%d", &numero);

    while (numero >= 0) {
        if (ehPrimo(numero)) {
            printf("Primo\n");
        } else {
            printf("Nao primo\n");
        }
        scanf("%d", &numero);
    }

    return 0;
}
