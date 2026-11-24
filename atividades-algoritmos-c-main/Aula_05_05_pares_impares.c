#include <stdio.h>

int main(void)
{
    int pares = 0;
    for (int i = 0; i < 10; i++) {
        int n;
        if (scanf("%d", &n) != 1) return 1;
        if (n % 2 == 0) {
            printf("%d é par.\n", n);
            pares++;
        } else {
            printf("%d é ímpar.\n", n);
        }
    }
    printf("Pares: %d\nÍmpares: %d\n", pares, 10 - pares);
    return 0;
}
