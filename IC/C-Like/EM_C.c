#include <stdio.h>

int main(){
    int N = 0;
    int T = 0;
    int contadorT1 = 0;
    int contadorT2 = 0;
    int P = 0;
    int M = 0;

    scanf("%d", &N);

    if(N >= 1 && N <= 1000){
        for(int i = 1; i <= N; i++){
            scanf("%d", &T);
            if(T == 1 || T == 2){
                if(T == 1){
                    contadorT1++;
                }
                if(T == 2){
                    contadorT2++;
                }
            }
        }
        scanf("%d", &P);
        if(P >= 0 && P <= 1000){
            scanf("%d", &M);
            if(M >= 0 && M <= 1000){
                if(N <= P + M){
                    if(P >= contadorT1 && M >= contadorT2){
                        printf("S");
                    }
                    else{
                        printf("N");
                    }
                }
            }
        }
    }
    return 0;
}
