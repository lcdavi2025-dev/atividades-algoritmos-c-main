#include <stdio.h>

int main(void)
{
    int valores[10], alvo, posicoes[10], total = 0;
    for (int i = 0; i < 10; i++) {
        if (scanf("%d", &valores[i]) != 1) return 1;
    }
    printf("Número para pesquisar: ");
    if (scanf("%d", &alvo) != 1) return 1;
    for (int i = 0; i < 10; i++) {
        if (valores[i] == alvo) posicoes[total++] = i;
    }
    if (total == 0) {
        puts("Número não encontrado.");
        return 0;
    }
    printf("O número %d foi encontrado %d vez(es).\nPosições: ", alvo, total);
    for (int i = 0; i < total; i++) printf("%d%s", posicoes[i], i + 1 == total ? "\n" : ", ");
    return 0;
}
