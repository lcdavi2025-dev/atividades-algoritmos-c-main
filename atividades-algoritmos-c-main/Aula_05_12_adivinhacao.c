#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand((unsigned)time(NULL));
    int secreto = rand() % 100 + 1;
    for (int tentativa = 1; tentativa <= 10; tentativa++) {
        int palpite;
        printf("Tentativa %d: ", tentativa);
        if (scanf("%d", &palpite) != 1) return 1;
        if (palpite == secreto) {
            printf("Parabéns! Você acertou em %d tentativa(s)!\n", tentativa);
            return 0;
        }
        puts(palpite < secreto ? "O número secreto é maior." : "O número secreto é menor.");
    }
    printf("10 tentativas. O número secreto era %d.\n", secreto);
    return 0;
}
