#include <stdio.h>
#include <math.h>

int main(){

    int i = 0;
    int j = 0;
    int n = 0;

    printf("Digite a altura do triangulo de estrelas:\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        for(j = 0; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }
}


