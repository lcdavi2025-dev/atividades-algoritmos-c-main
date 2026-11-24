#include <stdio.h>

int main(void)
{
    long long somaPos = 0, somaNeg = 0;
    int positivos = 0, negativos = 0, n;
    while (scanf("%d", &n) == 1 && n != 0) {
        if (n > 0) { somaPos += n; positivos++; }
        else { somaNeg += n; negativos++; }
    }
    printf("Positivos: %d, soma %lld\nNegativos: %d, soma %lld\n",
           positivos, somaPos, negativos, somaNeg);
    return 0;
}
