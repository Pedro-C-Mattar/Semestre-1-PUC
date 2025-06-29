#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void compararForca(int f1, int f2){

    printf("Estou no procedimento!\n");

    if(f1 > f2){
        printf("%d > %d\n", f1, f2);
    }
    else if(f2 > f1){
        printf("%d > %d\n", f2, f1);
    }
    else{
        printf("%d igual a %d\n", f2, f1);
    }

    printf("saindo do procedimento!\n");

}

int main(){
    int n = 0;
    int i = 0;
    int forca1 = 0;
    int forca2 = 0;

    printf("Quantos conjuntos voce deseja verificar?:\n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        printf("conjunto %d:\n", i);
        printf("Digite a forca do 1 gigante:\n");
        scanf("%d", &forca1);
        printf("Digite a forca do 2 gigante:\n");
        scanf("%d", &forca2);
        printf("Chamando o procedimento!\n");
        compararForca(forca1, forca2);
        printf("Voltou do procedimento!\n");
    }
}


