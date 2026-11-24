#include <stdio.h>

enum { DIAS = 5 };

static double calcularTotal(const double vendas[])
{
    double total = 0;
    for (int i = 0; i < DIAS; i++) total += vendas[i];
    return total;
}

static double calcularMedia(double total, int dias)
{
    return total / dias;
}

static int contarVendasAcimaDaMedia(const double vendas[], double media)
{
    int dias = 0;
    for (int i = 0; i < DIAS; i++) {
        if (vendas[i] > media) dias++;
    }
    return dias;
}

int main(void)
{
    double vendas[DIAS];
    for (int i = 0; i < DIAS; i++) {
        if (scanf("%lf", &vendas[i]) != 1 || vendas[i] < 0) return 1;
    }
    double total = calcularTotal(vendas);
    double media = calcularMedia(total, DIAS);
    printf("Total: %.2f\nMédia diária: %.2f\nDias acima: %d\n",
           total, media, contarVendasAcimaDaMedia(vendas, media));
    return 0;
}
