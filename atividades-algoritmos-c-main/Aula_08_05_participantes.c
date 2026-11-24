#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[80];
    long double id;
    int linha;
} Participante;

static long double fatorial(int n)
{
    long double produto = 1;
    for (int i = 2; i <= n; i++) produto *= i;
    return produto;
}

static int existeId(const Participante pessoas[], int qtd, long double id)
{
    for (int i = 0; i < qtd; i++) {
        if (pessoas[i].id == id) return 1;
    }
    return 0;
}

static int porNome(const void *a, const void *b)
{
    return strcmp(((const Participante *)a)->nome, ((const Participante *)b)->nome);
}

static long double mediaPonderada(const double valores[], int qtd)
{
    long double soma = 0, pesos = 0;
    for (int i = 0; i < qtd; i++) {
        long double peso = i + 1;
        soma += valores[i] * peso;
        pesos += peso;
    }
    return soma / pesos;
}

int main(void)
{
    Participante pessoas[4] = {0};
    int quantidade;
    printf("Quantidade de valores por participante: ");
    if (scanf("%d", &quantidade) != 1 || quantidade < 1) return 1;
    if ((size_t)quantidade > SIZE_MAX / sizeof(double) / 4) return 1;
    double (*valores)[quantidade] = malloc(4 * sizeof *valores);
    if (!valores) return 1;
    double lados[2];
    int ladosLidos = 0;

    for (int i = 0; i < 4; i++) {
        int idade;
        printf("Nome e idade (1 a 170), em linhas separadas:\n");
        if (scanf(" %79[^\n] %d", pessoas[i].nome, &idade) != 2 || idade < 1 || idade > 170) {
            free(valores);
            return 1;
        }
        pessoas[i].linha = i;
        pessoas[i].id = fatorial(idade) / 2;
        if (existeId(pessoas, i, pessoas[i].id)) {
            long double base = fatorial(idade / 2);
            for (int tentativa = 0; tentativa < 4; tentativa++) {
                pessoas[i].id = powl(base, (long double)quantidade + tentativa);
                if (isfinite(pessoas[i].id) && !existeId(pessoas, i, pessoas[i].id)) break;
            }
            /* Uma base igual a 1 sempre produz 1. Usa um ID de reserva se necessário. */
            if (!isfinite(pessoas[i].id) || existeId(pessoas, i, pessoas[i].id)) {
                pessoas[i].id = 1;
                while (existeId(pessoas, i, pessoas[i].id)) pessoas[i].id++;
            }
        }
        for (int j = 0; j < quantidade; j++) {
            printf("Valor %d de %s: ", j + 1, pessoas[i].nome);
            if (scanf("%lf", &valores[i][j]) != 1 || !isfinite(valores[i][j])) {
                free(valores);
                return 1;
            }
            if (valores[i][j] >= 0 && ladosLidos < 2) lados[ladosLidos++] = valores[i][j];
        }
    }
    qsort(pessoas, 4, sizeof pessoas[0], porNome);
    if (ladosLidos < 2) puts("Não foi possível calcular a diagonal.");
    long double diagonal = ladosLidos == 2 ? hypotl(lados[0], lados[1]) : 0;
    for (int i = 0; i < 4; i++) {
        long double media = mediaPonderada(valores[pessoas[i].linha], quantidade);
        const char *situacao = "Sem classificação";
        if (ladosLidos == 2) {
            long double tolerancia = 1e-12L * fmaxl(fabsl(media), diagonal);
            if (fabsl(media - diagonal) <= tolerancia) situacao = "Sobre a diagonal";
            else if (media > diagonal) situacao = "Acima da diagonal";
            else situacao = "Abaixo da diagonal";
        }
        printf("%s: %s\n", pessoas[i].nome, situacao);
    }
    free(valores);
    return 0;
}
