#include <stdio.h>

void verificaDivisibilidade(int num) {
    int div3 = (num % 3 == 0);
    int div5 = (num % 5 == 0);

    if (div3 && div5) {
        printf("Divisível por ambos\n");
    } else if (div3) {
        printf("Divisível por 3\n");
    } else if (div5) {
        printf("Divisível por 5\n");
    } else {
        printf("Não é divisível por 3 nem por 5\n");
    }
}

int main() {
    int num1, num2, num3;

    scanf("%d %d %d", &num1, &num2, &num3);

    verificaDivisibilidade(num1);
    verificaDivisibilidade(num2);
    verificaDivisibilidade(num3);

    return 0;
}
