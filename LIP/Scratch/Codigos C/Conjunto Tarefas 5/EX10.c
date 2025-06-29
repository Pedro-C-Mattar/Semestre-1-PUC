#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void separaPalavras(char pl[100]){
    int i = 0;

    printf("Estou no procedimento!\n");

    for(i=0;i < strlen(pl);i++){
        if (pl[i]== ' ' || pl[i]== ',' || pl[i]== '.' || pl[i]== ';' || pl[i]== '!' || pl[i]== '?') {
            printf("\n");
        }
        else{
            printf("%c", pl[i]);
        }
    }
    printf("\n");

    printf("saindo do procedimento!\n");
}

int main(){
    int n = 0;
    int i = 0;
    char palavra[100];

    printf("Quantas mensagens deseja decifrar?:\n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        printf("conjunto %d:\n", i);
        printf("Digite a %d mensagem secreta:\n", i);
        scanf(" %99[^\n]", palavra);
        printf("Chamando o procediemnto!\n");
        separaPalavras(palavra);
        printf("Voltou do procedimento!\n");
    }
}



