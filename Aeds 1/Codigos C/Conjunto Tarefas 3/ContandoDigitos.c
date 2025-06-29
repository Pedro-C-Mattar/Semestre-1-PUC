#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int contarDigitos(int n) {
    int contador = 0;

    if (n == 0) {
        return 1;
    }

    while (n != 0) {
        n = n / 10;
        contador++;
    }

    return contador;
}

int main() {
    int num = 0;
    int result = 0;
    scanf("%d", &num);
    result = contarDigitos(num);
    printf("%d", result);
}
