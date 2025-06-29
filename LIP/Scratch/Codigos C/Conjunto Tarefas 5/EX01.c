#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void dobroPoder(int p){
    int dobro = 0;

    printf("Estou no procedimento!\n");

    dobro = p * 2;

    printf("O dobro de %d = %d\n", p, dobro);

    printf("saindo do procedimento!\n");
}

int main(){
    int n = 0;
    int i = 0;
    int poder = 0;

    printf("Quantos numeros voce deseja?:\n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        printf("Digite um valor:\n");
        scanf("%d", &poder);
        printf("Chamando o procedimento com o parametro %d!\n", poder);
        dobroPoder(poder);
        printf("Voltou do procedimento!\n");
    }
}
