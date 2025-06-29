#include <stdio.h>
#include <math.h>

int main() {
    int num1 = 0;
    int num2 = 0;
    int maior = 0;

    while ((num1 >= 0) || (num2 >= 0)){
        printf("Digite o primeiro numero competidor:\n");
        scanf("%d", &num1);
        printf("Digite o segundo numero competidor:\n");
        scanf("%d", &num2);
        if((num1 >= 0) || (num2 >= 0)){
            if (num1 > num2){
                printf("O numero %d e o vencedor!\n", num1);
                if(num1 > maior){
                    maior = num1;
                }
            }
            else if (num2 > num1){
                printf("O numero %d e o vencedor!\n", num2);
                if(num2 > maior){
                    maior = num2;
                }
            }
            else{
                printf("O numero %d e igual ao numero %d!\n", num1, num2);
            }
        }
    }
    printf("Numero maior de todos:%d\n", maior);
}
