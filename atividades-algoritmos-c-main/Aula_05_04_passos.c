#include <stdio.h>

int main(void)
{
    long long total = 0;
    int horas = 0;
    while (total < 10000) {
        int passos;
        printf("Passos na hora %d: ", horas + 1);
        if (scanf("%d", &passos) != 1 || passos < 0) return 1;
        total += passos;
        horas++;
    }
    printf("Meta atingida em %d hora(s).\n", horas);
    return 0;
}
