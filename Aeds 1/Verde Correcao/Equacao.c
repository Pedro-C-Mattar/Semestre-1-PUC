#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    int delta, x1, x2;

    scanf("%d %d %d", &a, &b, &c);

    delta = pow(b,2) - (4 * a * c);

    if (delta < 0) {
        printf("Nao existem raizes reais\n");
    } else {

        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);

        printf("x1 = %d\n", x1);
        printf("x2 = %d\n", x2);
    }

    return 0;
}
