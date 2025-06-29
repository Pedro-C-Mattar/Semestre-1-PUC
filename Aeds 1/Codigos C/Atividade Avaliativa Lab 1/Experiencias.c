#include <stdio.h>
#include <math.h>

int main(){
    int i = 0;
    int n = 0;
    double coelhos = 0;
    double sapos = 0;
    double ratos = 0;
    double percentCoelho = 0;
    double percentSapo = 0;
    double percentRato = 0;
    double somaCobaias = 0;
    double cobaias = 0;
    char cobaiaTipo;

    scanf("%d", &n);

    while(i < n){
        if(i <= n){
            scanf("%lf %c", &cobaias, &cobaiaTipo);
            if((cobaias >= 1 && cobaias <= 15) && (cobaiaTipo == 'C' || cobaiaTipo == 'R' || cobaiaTipo == 'S')){
                somaCobaias = somaCobaias + cobaias;
                i++;
                if(cobaiaTipo == 'C'){
                    coelhos = coelhos + cobaias;
                }
                else if (cobaiaTipo == 'S'){
                    sapos = sapos + cobaias;
                }
                else if (cobaiaTipo == 'R'){
                    ratos = ratos + cobaias;
                }
            }
            else{
                printf("Algum valor invalido!\n");
            }
        }
    }

    percentCoelho = (coelhos / somaCobaias) * 100;
    percentSapo = (sapos / somaCobaias) * 100;
    percentRato = (ratos / somaCobaias) * 100;

    printf("Total: %.0lf cobaias\n", somaCobaias);
    printf("Total de coelhos: %.0lf\n", coelhos);
    printf("Total de ratos: %.0lf\n", ratos);
    printf("Total de sapos: %.0lf\n", sapos);
    printf("Percentual de coelhos: %.2lf %%\n", percentCoelho);
    printf("Percentual de ratos: %.2lf %%\n", percentRato);
    printf("Percentual de sapos: %.2lf %%", percentSapo);
}
