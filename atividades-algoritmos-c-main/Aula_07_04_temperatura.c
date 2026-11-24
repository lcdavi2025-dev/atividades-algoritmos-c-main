#include <stdio.h>

static double celsiusParaFahrenheit(double c)
{
    return 9 * c / 5 + 32;
}

int main(void)
{
    double celsius;
    if (scanf("%lf", &celsius) != 1) return 1;
    printf("%.2f °F\n", celsiusParaFahrenheit(celsius));
    return 0;
}
