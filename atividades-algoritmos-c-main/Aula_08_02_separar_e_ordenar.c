#include <stdio.h>
#include <stdlib.h>

static int crescente(const void *a, const void *b)
{
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}

static void exibir(const char *rotulo, const int vetor[], int quantidade)
{
    printf("%s:", rotulo);
    if (quantidade == 0) printf(" nenhum");
    for (int i = 0; i < quantidade; i++) printf(" %d", vetor[i]);
    putchar('\n');
}

int main(void)
{
    int positivosPares[10], negativosImpares[10];
    int qtdPositivos = 0, qtdNegativos = 0;
    for (int i = 0; i < 10; i++) {
        int valor;
        if (scanf("%d", &valor) != 1) return 1;
        if (valor > 0 && valor % 2 == 0) positivosPares[qtdPositivos++] = valor;
        if (valor < 0 && valor % 2 != 0) negativosImpares[qtdNegativos++] = valor;
    }
    qsort(positivosPares, qtdPositivos, sizeof positivosPares[0], crescente);
    qsort(negativosImpares, qtdNegativos, sizeof negativosImpares[0], crescente);
    exibir("Positivos pares", positivosPares, qtdPositivos);
    exibir("Negativos ímpares", negativosImpares, qtdNegativos);
    return 0;
}
