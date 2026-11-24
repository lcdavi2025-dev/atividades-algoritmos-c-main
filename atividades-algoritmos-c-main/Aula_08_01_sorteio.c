#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[80];
    double preco;
} Produto;

static int porNome(const void *a, const void *b)
{
    return strcmp(((const Produto *)a)->nome, ((const Produto *)b)->nome);
}

static int crescente(const void *a, const void *b)
{
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}
static int decrescente(const void *a, const void *b)
{
    return crescente(b, a);
}

int main(void)
{
    int numeros[12], distintos[12], ocorrencias[12] = {0}, pares[12];
    int total = 0, totalPares = 0;
    size_t quantidade = 0;
    for (int i = 0; i < 12; i++) {
        if (scanf("%d", &numeros[i]) != 1) return 1;
        int j = 0;
        while (j < total && distintos[j] != numeros[i]) j++;
        if (j == total) distintos[total++] = numeros[i];
        ocorrencias[j]++;
    }
    for (int i = 0; i < total; i++) {
        if (ocorrencias[i] % 2 == 0) pares[totalPares++] = distintos[i];
        else if (distintos[i] < 0) {
            puts("Quantidade de produtos não pode ser negativa.");
            return 1;
        } else {
            if ((size_t)distintos[i] > SIZE_MAX / sizeof(Produto) - quantidade) return 1;
            quantidade += (size_t)distintos[i];
        }
    }
    Produto *produtos = NULL;
    if (quantidade) {
        produtos = malloc(quantidade * sizeof *produtos);
        if (!produtos) return 1;
    }
    for (size_t i = 0; i < quantidade; i++) {
        printf("Nome e preço do produto %zu (em linhas separadas):\n", i + 1);
        if (scanf(" %79[^\n] %lf", produtos[i].nome, &produtos[i].preco) != 2 ||
            !(produtos[i].preco >= 0)) {
            free(produtos);
            return 1;
        }
    }
    if (quantidade > 1) qsort(produtos, quantidade, sizeof *produtos, porNome);
    qsort(pares, totalPares, sizeof pares[0], decrescente);
    printf("Números informados:");
    for (int i = 0; i < 12; i++) printf(" %d", numeros[i]);
    puts("\nOcorrências:");
    for (int i = 0; i < total; i++) printf("%d: %d\n", distintos[i], ocorrencias[i]);
    puts("Produtos:");
    for (size_t i = 0; i < quantidade; i++) printf("%s | R$ %.2f\n", produtos[i].nome, produtos[i].preco);
    printf("Números com frequência par:");
    for (int i = 0; i < totalPares; i++) printf(" %d", pares[i]);
    putchar('\n');
    free(produtos);
    return 0;
}
