#include <stdio.h>
#include <math.h>

void somatorio(){
    int i = 0;
    int soma = 0;
    int num = 0;

    printf("Estou no procedimento!\n");
    printf("Digite um valor:\n");
    scanf("%d", &num);

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
        printf("Chamando o procedimento!\n");
        somatorio();
        printf("Voltou do procedimento!\n");
    }

}
