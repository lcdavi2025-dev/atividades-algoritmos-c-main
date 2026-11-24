#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    char titulo[12];
    int zona;
} Eleitor;

typedef struct {
    Eleitor eleitor;
    int numero_voto;
} Cedula;

static int adicionar(Cedula **votos, size_t usados, const char titulo[], Cedula cedula)
{
    Cedula *novaLista = realloc(*votos, (usados + 1) * sizeof *novaLista);
    if (!novaLista) return 0;
    /* Um título de 12 dígitos ocupa o campo inteiro, sem terminador. */
    memcpy(cedula.eleitor.titulo, titulo, strlen(titulo));
    novaLista[usados] = cedula;
    *votos = novaLista;
    return 1;
}

static Cedula *recuperar(size_t *total)
{
    FILE *arquivo = fopen("urnas.bin", "rb");
    if (!arquivo) return NULL;
    long bytes = fseek(arquivo, 0, SEEK_END) == 0 ? ftell(arquivo) : -1;
    if (bytes <= 0 || (uintmax_t)bytes > SIZE_MAX || (size_t)bytes % sizeof(Cedula) ||
        fseek(arquivo, 0, SEEK_SET) != 0) {
        fclose(arquivo);
        return NULL;
    }
    size_t n = (size_t)bytes / sizeof(Cedula);
    Cedula *votos = malloc((size_t)bytes);
    int ok = votos && fread(votos, sizeof *votos, n, arquivo) == n;
    if (fclose(arquivo) != 0 || !ok) {
        free(votos);
        return NULL;
    }
    *total = n;
    return votos;
}

int main(void)
{
    size_t total;
    printf("Quantidade de votos: ");
    if (scanf("%zu", &total) != 1 || total == 0 || total > SIZE_MAX / sizeof(Cedula)) return 1;
    Cedula *votos = NULL;
    for (size_t i = 0; i < total; i++) {
        Cedula cedula = {0};
        char titulo[13];
        printf("Título (até 12 dígitos), zona e voto %zu: ", i + 1);
        if (scanf(" %12[0-9] %d %d", titulo, &cedula.eleitor.zona, &cedula.numero_voto) != 3 ||
            !adicionar(&votos, i, titulo, cedula)) {
            free(votos);
            return 1;
        }
    }
    FILE *arquivo = fopen("urnas.bin", "wb");
    int ok = 0;
    if (arquivo) {
        ok = fwrite(votos, sizeof *votos, total, arquivo) == total;
        if (fclose(arquivo) != 0) ok = 0;
    } else perror("urnas.bin");
    free(votos);
    if (!ok) return 1;
    votos = recuperar(&total);
    if (!votos) return 1;
    for (size_t i = 0; i < total; i++) {
        printf("Título %.12s | Zona %d | Voto %d\n",
               votos[i].eleitor.titulo, votos[i].eleitor.zona, votos[i].numero_voto);
    }
    free(votos);
    return 0;
}
