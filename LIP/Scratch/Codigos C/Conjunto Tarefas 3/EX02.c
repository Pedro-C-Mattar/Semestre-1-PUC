#include <stdio.h>
#include <math.h>

int main() {
    int i = 0;
    int j = 2;
    int n = 0;
    int num = 0;
    int menor = 9999999;

    printf("Digite o numero de series:\n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        printf("Digite o 1 numero da %d serie:\n", i);
        scanf("%d", &num);
        if(num < menor){
            menor = num;
        }
        if(num >= 0){
            while(num >= 0){
                printf("Digite o %d numero da %d serie (Flag valor negativo):\n", j, i);
                scanf("%d", &num);
                if(num >= 0){
                    if(num < menor){
                    menor = num;
                    }
                    j++;
                }
            }
            printf("O menor numero encontrado da %d serie = %d\n", i, menor);
        }
        else{
            printf("Nao existem numeros para essa serie!\n");
        }
        menor = 9999999;
        j = 2;
    }
}
