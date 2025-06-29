#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int seqFibonot(int n){
    int a = 1;
    int b = 1;
    int termo = 0;
    int num = 1;
    int contador = 0;
    int fibonot = 0;

    while (contador < n) {
        if (num == b) {
            termo = a + b;
            a = b;
            b = termo;
        } else {
            fibonot = num;
            contador++;
        }
        num++;
    }

    return fibonot;
}

int main() {
    int n = 0;
    int result = 0;

    scanf("%d", &n);
    if(n >= 1 && n <= 105){
       result = seqFibonot(n);
       printf("%d\n", result);
    }
    else{
        printf("Valor Invalido");
    }
}
