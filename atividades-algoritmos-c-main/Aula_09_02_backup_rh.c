#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char cargo[30];
    float salario;
} Funcionario;

int main(void)
{
    Funcionario *original = malloc(sizeof *original);
    Funcionario *backup = malloc(sizeof *backup);
    int ok = 0;
    if (original && backup) {
        memset(original, 0, sizeof *original);
        puts("Digite ID, cargo e salário em linhas separadas:");
        if (scanf("%d %29[^\n] %f", &original->id, original->cargo, &original->salario) == 3 &&
            original->salario >= 0) {
            memcpy(backup, original, sizeof *backup);
            FILE *arquivo = fopen("backup_rh.bin", "wb");
            if (arquivo) {
                ok = fwrite(backup, sizeof *backup, 1, arquivo) == 1;
                if (fclose(arquivo) != 0) ok = 0;
            } else perror("backup_rh.bin");
        }
    }
    free(backup);
    free(original);
    if (!ok) return 1;
    puts("Backup salvo em backup_rh.bin.");
    return 0;
}
