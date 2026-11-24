#include <stdio.h>

int main(void)
{
    char nome[80];
    double media;
    if (scanf(" %79[^\n] %lf", nome, &media) != 2) return 1;
    printf("%s - %.2f\n", nome, media);
    return 0;
}
