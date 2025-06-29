#include <stdio.h>
#include <math.h>

int num = 0;

void somatorio(){
    int i = 0;
    int soma = 0;

    printf("Estou no procedimento!\n");

    for(i = 1; i <= num; i++){
        soma = soma + i;
    }

    printf("Soma de 1 ate %d = %d\n", num, soma);
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
        somatorio();
        printf("Voltou do procedimento!\n");
    }

}

