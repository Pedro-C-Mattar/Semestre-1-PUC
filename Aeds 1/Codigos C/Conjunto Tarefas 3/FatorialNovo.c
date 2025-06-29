#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    char acm[6];
    int decimal;
    int length;
    int digito;
    int posicao;
    int fatorial;
    int i;
    int j;

    scanf("%s", acm);

    while (acm[0] != '0' || acm[1] != '\0') {
        decimal = 0;
        length = 0;

        while (acm[length] != '\0') {
            length++;
        }

        for (i = 0; i < length; i++) {
            digito = acm[i] - '0';
            posicao = length - i;
            fatorial = 1;

            for (j = 1; j <= posicao; j++) {
                fatorial = fatorial * j;
            }

            decimal = decimal + (digito * fatorial);
        }

        printf("%d\n", decimal);

        scanf("%s", acm);
    }
}
