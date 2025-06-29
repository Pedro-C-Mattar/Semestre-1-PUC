#include <stdio.h>
#include <math.h>

int main() {

    int monica, filho1, filho2;

    scanf("%d", &monica);
    scanf("%d", &filho1);
    scanf("%d", &filho2);

    if (filho1 > filho2){
        printf("%d", filho1);
    }
    if (filho2 > filho1){
        printf("%d", filho2);
    }
    if (filho2 == filho1){
        printf("%d", filho1);
    }

}

