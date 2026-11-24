#include <stdio.h>

static int ehPrimo(int n)
{
    if (n < 2) return 0;
    for (int divisor = 2; divisor <= n / divisor; divisor++) {
        if (n % divisor == 0) return 0;
    }
    return 1;
}

int main(void)
{
    int vetor[15], frequencias[15] = {0};
    char animais[15][80];
    size_t cadastrados = 0;
    for (int i = 0; i < 15; i++) {
        if (scanf("%d", &vetor[i]) != 1) return 1;
    }
    for (int i = 0; i < 15; i++) {
        int primeira = 0;
        while (vetor[primeira] != vetor[i]) primeira++;
        frequencias[primeira]++;
    }
    for (int i = 0; i < 15; i++) {
        int qtd = frequencias[i];
        if (qtd <= 1) continue;
        printf("%d aparece %d vez(es).\n", vetor[i], qtd);
        if (qtd % 2 != 0 && ehPrimo(vetor[i])) {
            long long soma = (long long)vetor[i] * qtd;
            printf("Nome do animal para a soma %lld: ", soma);
            if (scanf(" %79[^\n]", animais[cadastrados]) != 1) return 1;
            cadastrados++;
        }
    }
    for (int i = 0; i < 15; i++) {
        if (frequencias[i] > 1 && frequencias[i] % 2 == 0) {
            printf("Número %d (posição %d): %s\n", vetor[i], i + 1,
                   (size_t)i < cadastrados ? animais[i] : "Não existe correspondência.");
        }
    }
    return 0;
}
