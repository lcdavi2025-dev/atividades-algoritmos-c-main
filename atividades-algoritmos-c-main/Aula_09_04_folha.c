#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    int registro;
    int horas_aula;
} Professor;

static Professor *carregar(size_t n)
{
    FILE *arquivo = fopen("folha.dat", "rb");
    if (!arquivo) return NULL;
    Professor *resultado = malloc(n * sizeof *resultado);
    int ok = resultado && fread(resultado, sizeof *resultado, n, arquivo) == n;
    if (fclose(arquivo) != 0 || !ok) {
        free(resultado);
        return NULL;
    }
    return resultado;
}

int main(void)
{
    size_t n;
    printf("Quantos professores? ");
    if (scanf("%zu", &n) != 1 || n == 0 || n > SIZE_MAX / sizeof(Professor)) return 1;
    size_t bytes = n * sizeof(Professor);
    Professor *professores = calloc(n, sizeof *professores);
    unsigned char *buffer = malloc(bytes);
    if (!professores || !buffer) {
        free(professores);
        free(buffer);
        return 1;
    }
    for (size_t i = 0; i < n; i++) {
        printf("Registro e horas de aula do professor %zu: ", i + 1);
        if (scanf("%d %d", &professores[i].registro, &professores[i].horas_aula) != 2 ||
            professores[i].horas_aula < 0) {
            free(professores);
            free(buffer);
            return 1;
        }
    }
    memcpy(buffer, professores, bytes);
    free(professores);
    FILE *arquivo = fopen("folha.dat", "wb");
    int ok = 0;
    if (arquivo) {
        ok = fwrite(buffer, bytes, 1, arquivo) == 1;
        if (fclose(arquivo) != 0) ok = 0;
    } else perror("folha.dat");
    free(buffer);
    if (!ok) return 1;
    Professor *recuperados = carregar(n);
    if (!recuperados) return 1;
    for (size_t i = 0; i < n; i++) {
        printf("Registro %d | %d hora(s)\n", recuperados[i].registro, recuperados[i].horas_aula);
    }
    free(recuperados);
    return 0;
}
