#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int calcularPotencia(int bs, int exp){
    int potencia = 1;
    int i = 0;

    printf("Estou na funcao!\n");

    for(i = 1; i<=exp; i++){
        potencia = potencia * bs;
    }

    printf("saindo da funcao!\n");

    return potencia;
}

int main(){
    int n = 0;
    int i = 0;
    int base = 0;
    int expoente = 0;
    int result = 0;

    printf("Quantas formulas deseja calcular?:\n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        printf("conjunto %d:\n", i);
        printf("Digite a base:\n");
        scanf("%d", &base);
        printf("Digite o expoente:\n");
        scanf("%d", &expoente);
        printf("Chamando a funcao!\n");
        result = calcularPotencia(base, expoente);
        printf("Voltou da funcao\n");
        printf("%d elevado a %d = %d\n", base, expoente, result);
    }
}

