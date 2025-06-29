#include <stdio.h>
#include <math.h>

int main() {

    int a, b, c, d, diferenca1, diferenca2, diferenca3, menor;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);

    diferenca1 = abs((a + b) - (c + d));
    diferenca2 = abs((a + c) - (b + d));
    diferenca3 = abs((a + d) - (b + c));

    menor = fmin(fmin(diferenca1, diferenca2), diferenca3);

    printf("%d", menor);

}


