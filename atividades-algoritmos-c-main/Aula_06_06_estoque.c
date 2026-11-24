#include <stdio.h>

int main(void)
{
    int quantidades[10], maisDe20 = 0, maior = 0;
    for (int i = 0; i < 10; i++) {
        if (scanf("%d", &quantidades[i]) != 1 || quantidades[i] < 0) return 1;
        if (quantidades[i] > quantidades[maior]) maior = i;
        if (quantidades[i] > 20) maisDe20++;
    }
    for (int i = 0; i < 10; i++) {
        int qtd = quantidades[i];
        printf("Produto %d: %d unidade(s)", i + 1, qtd);
        if (qtd < 5) printf(" | estoque baixo");
        if (qtd == 0) printf(" | esgotado");
        putchar('\n');
    }
    printf("Com mais de 20: %d\nMaior estoque: produto %d (%d)\n", maisDe20, maior + 1, quantidades[maior]);
    return 0;
}
