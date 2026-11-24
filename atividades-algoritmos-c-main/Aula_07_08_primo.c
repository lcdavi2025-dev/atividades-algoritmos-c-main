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
    int n;
    if (scanf("%d", &n) != 1) return 1;
    puts(ehPrimo(n) ? "Primo" : "Não é primo.");
    return 0;
}
