#include <stdio.h>
#include <math.h>

typedef struct {
    int conta_corrente;
    char nome[50];
    float saldo;
} Cliente;

int main(void)
{
    int conta;
    float movimento;
    puts("Digite a conta e o valor (positivo para depósito, negativo para saque):");
    if (scanf("%d %f", &conta, &movimento) != 2 || !isfinite(movimento)) return 1;
    FILE *arquivo = fopen("clientes.bin", "rb+");
    if (!arquivo) { perror("clientes.bin"); return 1; }
    Cliente cliente;
    while (fread(&cliente, sizeof cliente, 1, arquivo) == 1) {
        if (cliente.conta_corrente != conta) continue;
        cliente.saldo += movimento;
        if (!isfinite(cliente.saldo)) {
            fclose(arquivo);
            return 1;
        }
        int ok = fseek(arquivo, -(long)sizeof cliente, SEEK_CUR) == 0 &&
                 fwrite(&cliente, sizeof cliente, 1, arquivo) == 1;
        if (fclose(arquivo) != 0 || !ok) return 1;
        printf("Saldo atualizado: R$ %.2f\n", cliente.saldo);
        return 0;
    }
    int erro = ferror(arquivo);
    if (fclose(arquivo) != 0 || erro) return 1;
    puts("Conta não encontrada.");
    return 0;
}
