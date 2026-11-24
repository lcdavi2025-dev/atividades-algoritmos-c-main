#include <stdio.h>

int main(void)
{
    char resposta;
    do {
        int n;
        printf("Número: ");
        if (scanf("%d", &n) != 1) return 1;
        for (int i = 1; i <= 10; i++) {
            printf("%d x %d = %lld\n", n, i, 1LL*n*i);
        }
        printf("Outra tabuada? (s/n): ");
    } while (scanf(" %c", &resposta) == 1 && (resposta == 's' || resposta == 'S'));
    return 0;
}
