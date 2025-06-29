#include <stdio.h>
#include <math.h>

int main(){

    int num = 0;
    int i = 0;
    int primo = 1;

    while(num > -1){

        scanf("%d", &num);

        if(num > -1){
            if (num <= 1) {
                printf("Nao primo\n");
            }
            else if (num == 2) {
                printf("Primo\n");
            }
            else if (num % 2 == 0) {
                printf("Nao primo\n");
            }
            else{
                for (i = 2; i <= sqrt(num); i++) {
                    if (num % i == 0) {
                        primo = 0;
                        i = num;
                    }
                }
                if(primo == 1){
                    printf("Primo\n");
                }
                else{
                    printf("Nao primo\n");
                }
            }
        }
    }
}
