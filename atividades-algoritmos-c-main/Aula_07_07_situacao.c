#include <stdio.h>

static double calcularMedia(double a, double b, double c)
{
    return (a + b + c) / 3;
}

static void verificarSituacao(double media)
{
    puts(media >= 7 ? "Aprovado" : "Reprovado");
}

int main(void)
{
    double a, b, c;
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return 1;
    double media = calcularMedia(a, b, c);
    printf("Média: %.2f\n", media);
    verificarSituacao(media);
    return 0;
}
