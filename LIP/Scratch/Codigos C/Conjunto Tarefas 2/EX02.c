#include <stdio.h>
#include <math.h>

int main(){

    int contador = 0;
    int num = 0;

    printf("Digite o valor inicial:\n");
    scanf("%d", &num);

    while(contador < 10){

        if(num % 2 != 0){
            printf("%d,", num);
            contador++;
        }
        num++;
    }
}

