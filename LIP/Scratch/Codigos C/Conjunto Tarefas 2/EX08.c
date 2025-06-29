#include <stdio.h>
#include <math.h>

int main(){

    int i = 0;
    int num = 0;
    int produto = 0;

    printf("Digite um numero para ver sua tabuada:\n");
    scanf("%d", &num);

    for(i = 1; i <= 10; i++){
        produto = num * i;
        printf("%2d x %2d =%3d\n", num, i, produto);
    }
}


