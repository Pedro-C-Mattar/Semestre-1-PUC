

#include <stdio.h>

int recorrencia(int n) {
    if(n == 0) return 1;

    return 2 * recorrencia(n - 1) + 3;
}

int main()
{
    int n;

    scanf("%d", &n);

    printf("%d", recorrencia(n));;

    return 0;
}
