#include <stdio.h>

int main(void)
{
    int maior, menor;
    if (scanf("%d", &maior) != 1) return 1;
    menor = maior;
    for (int i = 1; i < 10; i++) {
        int n;
        if (scanf("%d", &n) != 1) return 1;
        if (n > maior) maior = n;
        if (n < menor) menor = n;
    }
    printf("Maior: %d\nMenor: %d\nDiferença: %lld\n", maior, menor, (long long)maior - menor);
    return 0;
}
