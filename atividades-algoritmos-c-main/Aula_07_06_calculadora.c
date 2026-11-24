#include <stdio.h>

static double somar(double a, double b)
{
    return a + b;
}

static double subtrair(double a, double b)
{
    return a - b;
}

static double multiplicar(double a, double b)
{
    return a * b;
}

static double dividir(double a, double b)
{
    return a / b;
}

int main(void)
{
    double a, b, resultado;
    char op;
    puts("Digite uma expressão (ex.: 8 / 2):");
    if (scanf("%lf %c %lf", &a, &op, &b) != 3) return 1;
    switch (op) {
        case '+': resultado = somar(a, b); break;
        case '-': resultado = subtrair(a, b); break;
        case '*': resultado = multiplicar(a, b); break;
        case '/':
            if (b == 0) { puts("Divisão por zero."); return 1; }
            resultado = dividir(a, b);
            break;
        default: puts("Operação inválida."); return 1;
    }
    printf("Resultado: %.2f\n", resultado);
    return 0;
}
