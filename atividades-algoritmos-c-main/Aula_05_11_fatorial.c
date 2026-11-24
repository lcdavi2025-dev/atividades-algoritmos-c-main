#include <stdio.h>

int main(void)
{
    int n, resultado = 1;
    do {
        printf("Digite um inteiro de 0 a 10: ");
        if (scanf("%d", &n) != 1) return 1;
    } while (n < 0 || n > 10);
    for (int i = 2; i <= n; i++) resultado *= i;
    printf("%d! = %d\n", n, resultado);
    return 0;
}
