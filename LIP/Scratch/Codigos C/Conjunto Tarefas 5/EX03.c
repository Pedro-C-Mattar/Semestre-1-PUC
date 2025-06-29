#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void saudarVisitante(char nm[50]){

    printf("Estou no procedimento!\n");

    printf("Ola,%s! Seja bem-vindo ao Reino!\n", nm);

    printf("saindo do procedimento!\n");
}

int main(){
    int n = 0;
    int i = 0;
    char nome[50];

    printf("Quantos visitantes voce deseja?:\n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        printf("Digite o %d nome:\n", i);
        scanf(" %49[^\n]", nome);
        printf("Chamando o procedimento!\n");
        saudarVisitante(nome);
        printf("Voltou do procedimento!\n");
    }
}

