#include <stdio.h>
#include <math.h>

int main(){

    int i = 0;
    int num = 0;
    int soma = 0;
    int n = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++){

        scanf("%d", &num);

        if(i % 2 == 0){
            soma = soma + num;
        }
        else{
            soma = soma - num;
        }
    }
    printf("%d", soma);
}


