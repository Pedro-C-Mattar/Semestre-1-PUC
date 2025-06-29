#include <stdio.h>
#include <math.h>

int main(){
    int num = 0;
    int inferior = 1;
    int superior = 1023;
    int palpite = 0;
    int i = 0;

    printf("Pense em um numero de 1 a 1023\n");
    scanf("%d", &num);
    printf("Neste caso para testar o programa me diga o numero que voce escolheu:\n");
    if((num >= 1) && (num <= 1023)){
       while(i < 10 && palpite != num){
            palpite = (inferior + superior) / 2;
            printf("O numerio >,< ou = %d\n", palpite);
            if(num < palpite){
                superior = palpite - 1;
            }
            else if (num > palpite){
                inferior = palpite + 1;
            }
            i++;
        }
        printf("Advinhei o numero %d em %d tentativas!\n", num, i);

        i = 0;
        inferior = 1;
        superior = 1023;
        palpite = 0;

        while((num >= 1) && (num <= 1023)){
            printf("Pense em um numero de 1 a 1023(flag valor <1)\n");
            scanf("%d", &num);
            printf("Neste caso para testar o programa me diga o numero que voce escolheu:\n");
            if((num >= 1) && (num <= 1023)){
                while(i < 10 && palpite != num){
                    palpite = (inferior + superior) / 2;
                    printf("O numerio >,< ou = %d\n", palpite);
                    if(num < palpite){
                        superior = palpite - 1;
                    }
                    else if (num > palpite){
                        inferior = palpite + 1;
                    }
                    i++;
                }
                printf("Advinhei o numero %d em %d tentativas!\n", num, i);
            }

        i = 0;
        inferior = 1;
        superior = 1023;
        palpite = 0;

        }
    }



}
