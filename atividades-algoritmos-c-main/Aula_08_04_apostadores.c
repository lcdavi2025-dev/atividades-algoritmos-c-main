#include <stdio.h>

/* Considera os primeiros termos como 1, 1, 2, 3, ... */
static long long somaFibonacci(int termos)
{
    long long anterior = 0, atual = 1, soma = 0;
    for (int i = 0; i < termos; i++) {
        soma += atual;
        long long proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }
    return soma;
}

static int ehPrimo(long long n)
{
    if (n < 2) return 0;
    for (long long divisor = 2; divisor <= n / divisor; divisor++) {
        if (n % divisor == 0) return 0;
    }
    return 1;
}

int main(void)
{
    char nomes[5][80];
    long long resultados[5], total = 0;
    int premiado[5] = {0};
    for (int i = 0; i < 5; i++) {
        int termos;
        printf("Nome e quantidade de termos (1 a 40), em linhas separadas:\n");
        if (scanf(" %79[^\n] %d", nomes[i], &termos) != 2 || termos < 1 || termos > 40) return 1;
        resultados[i] = somaFibonacci(termos);
        total += resultados[i];
    }
    for (int lugar = 1; lugar <= 3; lugar++) {
        int vencedor = -1;
        for (int i = 0; i < 5; i++) {
            if (premiado[i]) continue;
            long long n = resultados[i];
            int elegivel = lugar == 1 ? ehPrimo(n) :
                           lugar == 2 ? n % 2 == 0 : n * 5 > total;
            if (elegivel && (vencedor < 0 || n > resultados[vencedor])) vencedor = i;
        }
        if (vencedor >= 0) {
            premiado[vencedor] = 1;
            printf("%dº lugar: %s\n", lugar, nomes[vencedor]);
        }
    }
    return 0;
}
