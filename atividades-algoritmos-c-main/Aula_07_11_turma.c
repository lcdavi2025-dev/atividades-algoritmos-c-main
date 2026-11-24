#include <stdio.h>

enum { ALUNOS = 10 };

static double calcularMediaTurma(const double notas[])
{
    double soma = 0;
    for (int i = 0; i < ALUNOS; i++) soma += notas[i];
    return soma / ALUNOS;
}

static double encontrarMaiorNota(const double notas[])
{
    double maior = notas[0];
    for (int i = 1; i < ALUNOS; i++) {
        if (notas[i] > maior) maior = notas[i];
    }
    return maior;
}

static int contarAprovados(const double notas[])
{
    int aprovados = 0;
    for (int i = 0; i < ALUNOS; i++) {
        if (notas[i] >= 7) aprovados++;
    }
    return aprovados;
}

static void exibirResultados(double media, double maior, int aprovados)
{
    printf("Média: %.2f\nMaior nota: %.2f\nAprovados: %d\n", media, maior, aprovados);
}

int main(void)
{
    double notas[ALUNOS];
    for (int i = 0; i < ALUNOS; i++) {
        if (scanf("%lf", &notas[i]) != 1 || !(notas[i] >= 0 && notas[i] <= 10)) return 1;
    }
    exibirResultados(calcularMediaTurma(notas), encontrarMaiorNota(notas), contarAprovados(notas));
    return 0;
}
