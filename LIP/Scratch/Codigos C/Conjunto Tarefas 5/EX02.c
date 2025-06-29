#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void verificarMaioridade(int id){

    printf("Estou no procedimento!\n");

    if(id >= 18){
        printf("Maior de idade\n");
    }
    else{
        printf("Menor de idade\n");
    }

    printf("saindo do procedimento!\n");
}

int main(){
    int n = 0;
    int i = 0;
    int idade = 0;

    printf("Quantas idades voce deseja verificar?:\n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        printf("Digite o %d valor:\n", i);
        scanf("%d", &idade);
        printf("Chamando o procedimento!\n");
        verificarMaioridade(idade);
        printf("Voltou do procedimento!\n");
    }
}

