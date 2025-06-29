#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int voto = 1;
    int i = 0;
    double contador = 0;
    int vt1 = 0;
    int vt2 = 0;
    int vt3 = 0;
    int vt4 = 0;
    int nulo = 0;
    double branco = 0;
    double percentBranc = 0;

    while(voto != 0){
        scanf("%d", &voto);
        if(voto != 0){
            if(voto == 1){
                vt1 = vt1 + 1;
            }
            else if(voto == 2){
                vt2 = vt2 + 1;
            }
            else if(voto == 3){
                vt3 = vt3 + 1;
            }
            else if(voto == 4){
                vt4 = vt4 + 1;
            }
            else if(voto == 5){
                nulo = nulo + 1;
            }
            else if(voto == 6){
                branco = branco + 1;
            }
            else if(voto < 0 || voto > 6){
                printf("Valor Invalido\n");
            }


            contador = contador + 1;
        }
    }

    percentBranc = (branco / contador) * 100;

    printf("Candidato 1: %d voto(s)\n", vt1);
    printf("Candidato 2: %d voto(s)\n", vt2);
    printf("Candidato 3: %d voto(s)\n", vt3);
    printf("Candidato 4: %d voto(s)\n", vt4);
    printf("Votos nulos: %d\n", nulo);
    printf("Porcentagem de votos em branco: %.2lf%%\n", percentBranc);
}
