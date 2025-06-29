#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
/*
void inverteString(int* numeros, int tamanho){
    if(tamanho == 0){
        return;
    }

    printf("%d", *(numeros + tamanho - 1));
    inverteString(numeros, tamanho-1);
}


int main (){
    int numeros[4];
    int num = 0;
    int tamanho = 4;

    for(int i = 0; i < 4; i++){
        scanf("%d", &num);
        numeros[i] = num;
    }

    inverteString(numeros, tamanho);
}
*/
//--------------------------------------------------------------------------------------------------//

int somaDigitos(int num){
    if(num % 10 == 0){
        return 0;
    }

    return (num%10) + somaDigitos(num / 10);

}


int main (){
    int num = 0;
    int result = 0;

    scanf("%d", &num);

    result = somaDigitos(num);
    printf("%d", result);
}
