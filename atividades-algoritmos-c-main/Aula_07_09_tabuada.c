#include <stdio.h>

static void mostrarTabuada(int n)
{
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %lld\n", n, i, 1LL*n*i);
    }
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 1;
    mostrarTabuada(n);
    return 0;
}
