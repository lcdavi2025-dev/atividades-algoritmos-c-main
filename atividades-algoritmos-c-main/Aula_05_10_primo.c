#include <stdio.h>

static int ehPrimo(int n)
{
    if (n < 2) return 0;
    for (int divisor = 2; divisor <= n / divisor; divisor++) {
        if (n % divisor == 0) return 0;
    }
    return 1;
}

int main(void)
{
    char resposta;
    do {
        int n;
        printf("Inteiro positivo: ");
        if (scanf("%d", &n) != 1 || n <= 0) return 1;
        puts(ehPrimo(n) ? "Primo" : "Não é primo.");
        printf("Testar outro número? (s/n): ");
    } while (scanf(" %c", &resposta) == 1 && (resposta == 's' || resposta == 'S'));
    return 0;
}
