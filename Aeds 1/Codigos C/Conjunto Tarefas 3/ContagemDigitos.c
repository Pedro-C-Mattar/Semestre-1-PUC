#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void contagemDigito(int a, int b){
    int num;
    int temp;
    int i;
    int digito;
    int contador[10];

    for (i = 0; i < 10; i++) {
        contador[i] = 0;
    }

    for (num = a; num <= b; num++) {
        temp = num;
        do {
            digito = temp % 10;
            contador[digito]++;
            temp = temp / 10;
        } while (temp > 0);
    }

    for (i = 0; i < 10; i++) {
        printf("%d ", contador[i]);
    }

    printf("\n");
}

int main() {
    int a = 1;
    int b = 1;

    while (a != 0 && b != 0) {
        scanf("%d %d", &a, &b);

        if((a >= 1 && a <= b) && (b >= a && b <= 108)){
            contagemDigito(a, b);
        }
        else if(a == 0 && b == 0){

        }
        else{
            printf("Valor Invalido\n");
        }
    }
}
