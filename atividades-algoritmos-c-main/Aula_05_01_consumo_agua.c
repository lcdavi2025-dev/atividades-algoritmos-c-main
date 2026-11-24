#include <stdio.h>

int main(void)
{
    double soma = 0;
    for (int i = 1; i <= 5; i++) {
        double consumo;
        printf("Consumo do morador %d (m³): ", i);
        if (scanf("%lf", &consumo) != 1 || consumo < 0) return 1;
        puts(consumo <= 20 ? "Dentro da média" : "Acima da média");
        soma += consumo;
    }
    printf("Consumo médio: %.2f m³\n", soma / 5);
    return 0;
}
