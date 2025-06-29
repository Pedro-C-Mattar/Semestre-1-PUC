#include <stdio.h>
#include <math.h>

int main() {

    int n = 0;
    int i = 0;
    int j = 0;
    int anterior = 0;
    int atual = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        anterior = 1;
        for(j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                atual = 1;
            }
            else{
                atual = anterior * (i - j + 1) / j;
            }
            printf("%d ", atual);
            anterior = atual;
        }
        printf("\n");
    }
}
