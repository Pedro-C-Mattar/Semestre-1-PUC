#include<stdio.h>
#include<stdlib.h>
void preencheVetor(int [], int n);
void imprimirVetor(int [], int n);
int parSoma(int [], int n);
int main ()
{
    int n, somas;
    scanf("%d",&n);
    int v[n];
    preencheVetor(v, n);
    imprimirVetor(v, n);
    printf("\n");
    parSoma( v, n);
    somas= parSoma(v, n);
    printf("O valor das somas e %d", somas);
}
void preencheVetor(int v[], int n)
{
    srand(time(NULL));
    for(int i=0; i<n; i++)
    {
        int numeroAle= rand()%100;
        v[i]=numeroAle;
    }
}
void imprimirVetor(int v[], int n)
{
    for(int i =0; i<n; i++)
    {
        printf("%d\t", v[i]);
    }
}
int parSoma(int v[], int n)
{
    int soma=0;
    for(int i=0; i<n; i++)
    {
        if(v[i]%2==0)
        {
            soma+=i;
        }
    }
    return soma;
}
