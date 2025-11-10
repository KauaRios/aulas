#include <stdio.h>
#include <stdlib.h>

int main() {
    int* numeros = malloc(3 * sizeof(int));

    numeros[0] = 10;
    numeros[1] = 20;
    numeros[2] = 30;

    numeros = realloc(numeros, 5 * sizeof(int));

    numeros[3] = 40;
    numeros[4] = 50;

    for(int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    free(numeros);

    return 0;
}
