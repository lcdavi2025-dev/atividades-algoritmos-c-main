#include <stdio.h>

typedef struct {
    int conta_corrente;
    char nome[50];
    float saldo;
} Cliente;

int main(void)
{
    const Cliente exemplos[] = {{101, "Ana Lima", 500.0f}, {202, "Bruno Dias", 250.0f}};
    FILE *arquivo = fopen("clientes.bin", "wbx");
    if (!arquivo) { perror("clientes.bin"); return 1; }
    int ok = fwrite(exemplos, sizeof exemplos[0], 2, arquivo) == 2;
    if (fclose(arquivo) != 0 || !ok) return 1;
    puts("Arquivo criado com as contas 101 e 202.");
    return 0;
}
