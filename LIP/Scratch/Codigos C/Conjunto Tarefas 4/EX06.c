#include <stdio.h>
#include <math.h>

double media = 0;

void mediaNum(){
    double num = 0;
    double soma = 0;
    double contador = 0;
    media = 0;

    printf("Estou no procedimento!\n");

    while(num >= 0){
        printf("Digite um valor (FLAG valor negativo)\n");
        scanf("%lf", &num);
        if(num >= 0){
            soma = soma + num;
            contador = contador + 1;
        }
    }
    if(contador > 0){
        media = soma / contador;
    }
    printf("saindo do procedimento!\n");
}

int main(){
    int n = 0;
    int i = 0;

    printf("Quantos conjuntos voce deseja?:\n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        printf("Chamando o procedimento!\n");
        mediaNum();
        printf("Voltou do procedimento!\n");
        printf("A media do %d conjunto foi:%.3lf\n", i, media);
    }
}


