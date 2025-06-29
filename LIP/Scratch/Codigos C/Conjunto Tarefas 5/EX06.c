#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int verificarParidade(int num){

    printf("Estou no procedimento!\n");

    printf("saindo do procedimento!\n");

    if(num % 2 == 0){
        return 2;
    }
    else{
        return 1;
    }
}

int main(){
    int n = 0;
    int i = 0;
    int numero = 0;
    int result;

    printf("Quantos numeros voce deseja verificar?:\n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        printf("Digite um valor:\n");
        scanf("%d", &numero);
        printf("Chamando o procedimento!\n");
        result = verificarParidade(numero);
        printf("Voltou do procedimento!\n");
        if(result == 2){
           printf("O numero %d : par\n", numero);
        }
        else{
            printf("O numero %d : impar\n", numero);
        }


    }
}

