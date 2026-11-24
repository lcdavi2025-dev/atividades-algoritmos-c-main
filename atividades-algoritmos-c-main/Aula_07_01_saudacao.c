#include <stdio.h>

static void mostrarSaudacao(void)
{
    puts("Bem-vindo ao mundo das funções em C!");
}

int main(void)
{
    for (int i = 0; i < 3; i++) mostrarSaudacao();
    return 0;
}
