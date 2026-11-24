#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int matriz[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = rand() % 1000;
            printf("%d%s", matriz[i][j], j == 2 ? "\n" : " - ");
        }
    }
    return 0;
}
