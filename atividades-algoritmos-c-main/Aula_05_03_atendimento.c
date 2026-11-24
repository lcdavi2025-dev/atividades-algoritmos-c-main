#include <stdio.h>

int main(void)
{
    double soma = 0;
    for (int i = 1; i <= 10; i++) {
        double nota;
        do {
            printf("Nota do cliente %d (0 a 10): ", i);
            if (scanf("%lf", &nota) != 1) return 1;
        } while (!(nota >= 0 && nota <= 10));
        soma += nota;
    }
    double media = soma / 10;
    printf("Média: %.2f\n", media);
    if (media < 7) puts("Alerta: média abaixo de 7.");
    return 0;
}
