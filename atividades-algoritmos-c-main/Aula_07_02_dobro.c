#include <stdio.h>

static long long calcularDobro(int n)
{
    return 2LL * n;
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 1;
    printf("Dobro: %lld\n", calcularDobro(n));
    return 0;
}
