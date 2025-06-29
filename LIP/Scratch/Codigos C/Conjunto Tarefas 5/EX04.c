#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

double calcularMedia(double nt1, double nt2){
    double media = 0;

    printf("Estou na funcao!\n");

    media = (nt1 + nt2) / 2;

    printf("saindo da funcao!\n");

    return media;
}

int main(){
    int n = 0;
    int i = 0;
    double nota1 = 0;
    double nota2 = 0;
    double result = 0;

    printf("Quantos apresentacoes foram realizadas?:\n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        printf("Digite as notas da %d apresentacao:\n", i);
        scanf("%lf", &nota1);
        scanf("%lf", &nota2);
        printf("Chamando a funcao!\n");
        result = calcularMedia(nota1, nota2);
        printf("Voltou da funcao!\n");
        printf("Media final:%.2lf\n", result);
    }
}
