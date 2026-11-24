#include <stdio.h>

int main(void)
{
    long long centavos = 0;
    for (;;) {
        int opcao;
        puts("1 - R$ 0,50 | 2 - R$ 1,00 | 3 - R$ 2,00 | 0 - Sair");
        if (scanf("%d", &opcao) != 1) return 1;
        if (!opcao) break;
        switch (opcao) {
            case 1: centavos += 50; break;
            case 2: centavos += 100; break;
            case 3: centavos += 200; break;
            default: puts("Opção inválida.");
        }
    }
    printf("Total: R$ %lld,%02lld\n", centavos / 100, centavos % 100);
    return 0;
}
