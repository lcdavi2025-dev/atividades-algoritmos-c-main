#include <stdio.h>

static int ehPar(int n)
{
    return n % 2 == 0;
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 1;
    puts(ehPar(n) ? "Par" : "Ímpar");
    return 0;
}
