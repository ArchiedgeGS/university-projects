#include <stdio.h>

int main() {
    int n;
    printf("Informe o número de linhas: ");
    scanf("%d", &n);

    int x;
    float y;
    char z;
    printf("\nInforme 3 valores (um inteiro, um real e um caracter): ");
    scanf("%d %f %c", &x, &y, &z);

    if (z >= 'a' && z <= 'z')
        z -= 32;

    printf("%-4d %.2f %c\n", x, y, z);
    x += 32;
    y *= 2;
    z++;

    for (int i = 1; i < n; i++) {
        printf("%-4d %.2f %c\n", x, y, z);
        x += 32;
        y *= 2;
        z++;
    }

    return 0;
}
