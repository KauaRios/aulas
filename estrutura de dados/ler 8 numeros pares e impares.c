#include <stdio.h>

int main() {
    int vet[8];
    int *p = vet;
    int pares = 0, impares = 0;

    puts("Digite 8 inteiros:");
    for (int i = 0; i < 8; i++) {
        scanf("%d", &vet[i]);  
    }

    p = vet;  
    for (int i = 0; i < 8; i++, p++) {
        if ((*p % 2) == 0)
            pares++;
        else
            impares++;
    }

    printf("\nPares: %d | Ímpares: %d\n", pares, impares);

    return 0;
}
