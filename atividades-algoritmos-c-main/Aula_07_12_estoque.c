#include <stdio.h>

enum { PRODUTOS = 8 };

static long long calcularTotalEstoque(const int quantidades[])
{
    long long total = 0;
    for (int i = 0; i < PRODUTOS; i++) total += quantidades[i];
    return total;
}

static int contarEstoqueBaixo(const int quantidades[])
{
    int total = 0;
    for (int i = 0; i < PRODUTOS; i++) {
        if (quantidades[i] < 5) total++;
    }
    return total;
}

static int buscarProduto(const int quantidades[], int codigo)
{
    if (codigo < 1 || codigo > PRODUTOS || quantidades[codigo - 1] < 0) return -1;
    return codigo - 1;
}

int main(void)
{
    int quantidades[PRODUTOS], codigo;
    for (int i = 0; i < PRODUTOS; i++) {
        if (scanf("%d", &quantidades[i]) != 1 || quantidades[i] < 0) return 1;
    }
    printf("Total: %lld\nEstoque baixo: %d produto(s)\n",
           calcularTotalEstoque(quantidades), contarEstoqueBaixo(quantidades));
    printf("Código para consulta: ");
    if (scanf("%d", &codigo) != 1) return 1;
    int posicao = buscarProduto(quantidades, codigo);
    if (posicao < 0) puts("Produto inexistente.");
    else printf("Índice %d: %d unidade(s).\n", posicao, quantidades[posicao]);
    return 0;
}
