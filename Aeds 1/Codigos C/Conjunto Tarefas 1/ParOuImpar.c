#include <stdio.h>
#include <math.h>

int main() {
    int num, mod;

    scanf("%d", &num);

    mod = num % 2;

    if (mod == 0){
        printf("par");
    }
    else{
        printf("impar");
    }
}
