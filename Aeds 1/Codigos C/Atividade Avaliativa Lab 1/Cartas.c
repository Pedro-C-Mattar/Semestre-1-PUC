#include <stdio.h>
#include <math.h>

int main(){
    int i = 1;
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;
    int num5 = 0;

    scanf("%d %d %d %d %d", &num1, &num2, &num3, &num4, &num5);

    if((num1 >= 1 && num1 <= 13) && (num2 >= 1 && num2 <= 13) && (num3 >= 1 && num3 <= 13) && (num4 >= 1 && num4 <= 13) && (num5 >= 1 && num5 <= 13)){
        if((num1 >= num2) && (num2 >= num3) && (num3 >= num4) && (num4 >= num5)){
            printf("D");
        }
        else if ((num1 <= num2) && (num2 <= num3) && (num3 <= num4) && (num4 <= num5)){
            printf("C");
        }
        else{
            printf("N");
        }
    }

}

