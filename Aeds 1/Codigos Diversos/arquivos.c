#include <stdio.h>
#include <stdlib.h>


/*
int main(){
    FILE* arquivo;
    arquivo = fopen("arquivo1.txt", "w");

    if(!arquivo){
        printf("Erro de Criação");
        return 1;
    }
    else{
        printf("Arquivo criado");
    }

    fclose(arquivo);

    return 0;
}
*/


/*
int main(){
    FILE* arquivo;

    system("md.c:\\temp");
    arquivo = fopen("C:\Users\882145\Documents\arquivo1.txt", "w");

    if(!arquivo){
        printf("Erro de Criação");
        return 1;
    }
    else{
        printf("Arquivo criado");
    }

    fclose(arquivo);

    return 0;
}
*/


/*
int main(){
    char letra;

    FILE* arquivo;
    arquivo = fopen("arquivo1.txt", "w");

    if(!arquivo){
        printf("Erro de Criação\n");
        return 1;
    }
    else{
        printf("Arquivo criado\n");
    }

    for(int i = 0; i < 5; i++){
       scanf(" %c", &letra);
       fputc(letra, arquivo);
    }

    fclose(arquivo);

    return 0;
}
*/


/*
int main(){
    char letra;

    FILE* arquivo;
    arquivo = fopen("arquivo1.txt", "r");

    while((letra = fgetc(arquivo)) != EOF){
        printf("%c", letra);
    }

    fclose(arquivo);

    return 0;
}
*/


/*
int main(){
    char letra;

    FILE* arquivo;
    arquivo = fopen("arquivo1.txt", "r");

    while(!feof(arquivo)){
        letra = fgetc(arquivo);
        printf("%c", letra);
    }

    fclose(arquivo);

    return 0;
}
*/


/*
int main(){
    int n1= 6;
    int n2 = 7;

    FILE* arquivo;
    arquivo = fopen("arquivo1.txt", "w");

    fprintf(arquivo, "%d %d", n1, n2);

    fclose(arquivo);

    return 0;
}
*/


/*
int main(){
    int n1;
    int n2;

    FILE* arquivo;
    arquivo = fopen("arquivo1.txt", "r");

    while((fscanf(arquivo, "%d %d", &n1, &n2)) != EOF){
        printf("Leu %d e %d\n", n1, n2);
    }

    fclose(arquivo);

    return 0;
}
*/


int main(){
    char letra[50];

    FILE* arquivo;
    arquivo = fopen("arquivo1.txt", "w");

    if(!arquivo){
        printf("Erro de Criação\n");
        return 1;
    }
    else{
        printf("Arquivo criado\n");
    }

    for(int i = 0; i < 5; i++){
       fgets(letra, 50, stdin);
       fputs(letra, arquivo);
    }

    fclose(arquivo);

    char nome[50];

    arquivo = fopen("arquivo1.txt", "r");

    while((fscanf(arquivo, " %s", nome)) != EOF){
        printf(" %s\n", nome);
    }

    return 0;
}
