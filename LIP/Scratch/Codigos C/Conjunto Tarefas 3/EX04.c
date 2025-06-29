#include <stdio.h>
#include <math.h>

int main() {

    int num = 0;

    printf("Digite um numero:\n");
    scanf("%d", &num);
    if(num >= 0){
        if (num % 5 == 0 && num % 3 == 0){
            printf("O numero %d e divisivel por 5 e 3 ao mesmo tempo\n", num);
        }
        else if(num % 5 == 0){
            printf("O numero %d e divisivel por 5 mas nao por 3\n", num);
        }
        else if(num % 3 == 0){
            printf("O numero %d e divisivel por 3 mas nao por 5\n", num);
        }
        else{
            printf("O numero %d nao e divisivel nem por 5 nem por 3\n", num);
        }
        if(num >= 0){
            while(num >= 0){
                printf("Digite um numero(flag valor negativo):\n");
                scanf("%d", &num);
                if (num >= 0){
                    if (num % 5 == 0 && num % 3 == 0){
                        printf("O numero %d e divisivel por 5 e 3 ao mesmo tempo\n", num);
                    }
                    else if(num % 5 == 0){
                        printf("O numero %d e divisivel por 5 mas nao por 3\n", num);
                    }
                    else if(num % 3 == 0){
                        printf("O numero %d e divisivel por 3 mas nao por 5\n", num);
                    }
                    else{
                        printf("O numero %d nao e divisivel nem por 5 nem por 3\n", num);
                    }
                }
            }
        }
    }
}
