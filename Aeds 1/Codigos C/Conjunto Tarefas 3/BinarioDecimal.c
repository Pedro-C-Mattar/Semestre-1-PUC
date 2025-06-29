#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int binarioParaDecimal(int binario) {
    int digito = 0;
    int resto = 0;

    if (binario == 0) {
        return 0;
    }
    if (binario > 0){
        digito = binario % 10;
        resto = binario / 10;
        return digito + 2 * binarioParaDecimal(resto);
    }
}

int main() {
    int num = 0;
    int result = 0;
    scanf("%d", &num);
    result = binarioParaDecimal(num);
    printf("%d", result);
}
