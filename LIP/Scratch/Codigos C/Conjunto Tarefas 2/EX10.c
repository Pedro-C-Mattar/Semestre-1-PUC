#include <stdio.h>
#include <math.h>

int main(){

    int lado = 0;
    char caractere;
    int i = 0;
    int j = 0;

    printf("Digite o tamanho do lado do quadrado:\n");
    scanf("%d", &lado);
    printf("Digite um caractere para formar o quadrado:\n");
    scanf(" %c", &caractere);

    for(i = 0; i < lado; i++){
        for(j = 0; j < lado; j++){
            printf("%c ", caractere);
        }
        printf("\n");
    }
}



