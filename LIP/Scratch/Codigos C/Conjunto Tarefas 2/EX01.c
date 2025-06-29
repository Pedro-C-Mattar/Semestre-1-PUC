#include <stdio.h>
#include <math.h>

int main(){

    int i = 0;
    int num = 0;
    int produto = 0;

    for(i = 1; i <= 5; i++){
        printf("Digite um numero:\n");
        scanf("%d", &num);
        produto = num * 3;
        printf("O tripo de %d = %d\n", num, produto);
    }
}
