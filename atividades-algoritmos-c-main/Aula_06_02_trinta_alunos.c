#include <stdio.h>

int main(void)
{
    char nomes[30][80];
    double medias[30];
    for (int i = 0; i < 30; i++) {
        printf("Nome e média do aluno %d (em linhas separadas):\n", i + 1);
        if (scanf(" %79[^\n] %lf", nomes[i], &medias[i]) != 2) return 1;
    }
    for (int i = 0; i < 30; i++) printf("%s - %.2f\n", nomes[i], medias[i]);
    return 0;
}
