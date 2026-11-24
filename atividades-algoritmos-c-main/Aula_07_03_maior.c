#include <stdio.h>

static int maiorNumero(int a, int b)
{
    return a >= b ? a : b;
}

int main(void)
{
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) return 1;
    printf("Maior: %d\n", maiorNumero(a, b));
    return 0;
}
