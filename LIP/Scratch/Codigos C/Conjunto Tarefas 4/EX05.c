#include <stdio.h>
#include <math.h>

void fibonacci(){
    int i = 0;
    int num = 0;
    int a = 1;
    int b = 1;
    int termo = 0;

    printf("Estou no procedimento!\n");
    printf("Digite quantos termos da serie:\n");
    scanf("%d", &num);
    if(num <= 0){
        printf("Voce escolheu um numero invalido!\n");
    }
    else if(num == 1){
        printf("%d\n", a);
    }
    else if(num == 2){
        printf("%d,%d\n", a, b);
    }
    else if(num > 2){
        printf("%d,%d", a, b);
        for(i = 3; i <= num; i++){
            termo = a + b;
            printf(",%d", termo);
            b = a;
            a = termo;

        }
        printf("\n");
    }

    printf("saindo do procedimento!\n");
}

int main(){
    int n = 0;
    int i = 0;

    printf("Quantos numeros voce deseja?:\n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        printf("Chamando o procedimento!\n");
        fibonacci();
        printf("Voltou do procedimento!\n");
    }
}


