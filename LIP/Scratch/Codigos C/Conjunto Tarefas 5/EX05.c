#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int contarLetras(char pl[100]){
    int contador = 0;
    int i = 0;

    printf("Estou na funcao!\n");

    for(i=0;i < strlen(pl);i++){
        if ((pl[i] >= 'A' && pl[i] <= 'Z') || (pl[i] >= 'a' && pl[i] <= 'z')) {
            contador++;
        }
    }

    printf("saindo da funcao!\n");

    return contador;
}

int main(){
    int n = 0;
    int i = 0;
    char palavra[100];
    int result = 0;

    printf("Quantas sentencas voce deseja contar as letras?:\n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        printf("Digite a %d sentenca:\n", i);
        scanf(" %99[^\n]", palavra);
        printf("Chamando a funcao!\n");
        result = contarLetras(palavra);
        printf("Voltou da funcao!\n");
        if(result == 1){
            printf("A sentenca %s possui %d letra\n", palavra, result);
        }
        else{
            printf("A sentenca %s possui %d letras\n", palavra, result);
        }
    }
}


