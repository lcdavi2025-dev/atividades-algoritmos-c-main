#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[50];
    float preco;
} Produto;

int main(void)
{
    Produto produtos[3];
    for (int i = 0; i < 3; i++) {
        printf("Código, nome e preço do produto %d, em linhas separadas:\n", i + 1);
        if (scanf("%d %49[^\n] %f", &produtos[i].codigo, produtos[i].nome, &produtos[i].preco) != 3 ||
            !(produtos[i].preco >= 0) || strchr(produtos[i].nome, '\t')) return 1;
    }
    FILE *arquivo = fopen("estoque.txt", "w");
    if (!arquivo) { perror("estoque.txt"); return 1; }
    int ok = 1;
    for (int i = 0; i < 3; i++) {
        if (fprintf(arquivo, "%d\t%s\t%.2f\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco) < 0) {
            ok = 0;
            break;
        }
    }
    if (fclose(arquivo) != 0 || !ok) return 1;
    arquivo = fopen("estoque.txt", "r");
    if (!arquivo) { perror("estoque.txt"); return 1; }
    puts("Código | Produto | Preço");
    for (int i = 0; i < 3; i++) {
        Produto p;
        if (fscanf(arquivo, "%d\t%49[^\t\n]\t%f", &p.codigo, p.nome, &p.preco) != 3) {
            fclose(arquivo);
            return 1;
        }
        printf("%d | %s | R$ %.2f\n", p.codigo, p.nome, p.preco);
    }
    if (fclose(arquivo) != 0) return 1;
    return 0;
}
