#include <stdio.h>
#include <math.h>

int num = 0;

void numPrimo(){
    int i = 0;
    int primo = 1;

    printf("Estou no procedimento!\n");
    if(num <= 1){
        printf("Numero %d nao eh primo!\n", num);
    }
    else if(num == 2){
        printf("Numero %d eh primo!\n", num);
    }
    else if(num % 2 == 0){
        printf("Numero %d nao eh primo!\n", num);
    }
    else{
        for (i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                primo = 0;
                i = num;
            }
        }
        if(primo == 1){
            printf("Numero %d eh primo!\n", num);
        }
        else{
            printf("Numero %d nao eh primo!\n", num);
        }
    }

    printf("saindo do procedimento!\n");
}

int main(){
    int n = 0;
    int i = 0;

    printf("Quantos numero voce deseja verificar?:\n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        printf("Digite o %d numero a ser verificado:\n", i);
        scanf("%d", &num);
        printf("Chamando o procedimento!\n");
        numPrimo();
        printf("Voltou do procedimento!\n");
    }
}



