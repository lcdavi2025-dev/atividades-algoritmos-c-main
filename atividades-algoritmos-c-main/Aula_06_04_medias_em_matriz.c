#include <stdio.h>

int main(void)
{
    double notas[3][4];
    for (int i = 0; i < 3; i++) {
        printf("Três notas do aluno %d: ", i + 1);
        if (scanf("%lf %lf %lf", &notas[i][0], &notas[i][1], &notas[i][2]) != 3) return 1;
        notas[i][3] = (notas[i][0] + notas[i][1] + notas[i][2]) / 3;
    }
    puts("Nota 1 | Nota 2 | Nota 3 | Média");
    for (int i = 0; i < 3; i++) {
        printf("%.2f | %.2f | %.2f | %.2f\n", notas[i][0], notas[i][1], notas[i][2], notas[i][3]);
    }
    return 0;
}
