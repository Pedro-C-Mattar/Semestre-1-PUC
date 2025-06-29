#include <stdio.h>
#include <math.h>

int num = 0;
int fatorial = 1;

void fatorialNum(){
    int i = 0;
    fatorial = 1;

    printf("Estou no procedimento!\n");

    for(i = 1; i <= num; i++){
        fatorial = fatorial * i;
    }

    printf("saindo do procedimento!\n");
}

int main(){
    int n = 0;
    int i = 0;

    printf("Quantos numeros voce deseja?:\n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        printf("Digite o %i valor:\n", i);
        scanf("%d", &num);
        printf("Chamando o procedimento!\n");
        fatorialNum();
        printf("Voltou do procedimento!\n");
        printf("O fatorial de %d = %d\n", num, fatorial);
    }
}

