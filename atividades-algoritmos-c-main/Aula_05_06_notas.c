#include <stdio.h>

int main(void)
{
    int aprovados = 0, recuperacao = 0, reprovados = 0;
    char resposta;
    printf("Registrar aluno? (s/n): ");
    while (scanf(" %c", &resposta) == 1 && (resposta == 's' || resposta == 'S')) {
        double soma = 0;
        for (int i = 1; i <= 3; i++) {
            double nota;
            do {
                printf("Nota %d (0 a 10): ", i);
                if (scanf("%lf", &nota) != 1) return 1;
            } while (!(nota >= 0 && nota <= 10));
            soma += nota;
        }
        double media = soma / 3;
        printf("Média: %.2f\n", media);
        if (media >= 7) { puts("Aprovado"); aprovados++; }
        else if (media >= 5) { puts("Recuperação"); recuperacao++; }
        else { puts("Reprovado"); reprovados++; }
        printf("Registrar outro aluno? (s/n): ");
    }
    printf("Aprovados: %d\nRecuperação: %d\nReprovados: %d\n", aprovados, recuperacao, reprovados);
    return 0;
}
