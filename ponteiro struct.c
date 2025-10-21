#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int idade;
} Pessoa;

int main()
{
    // p é um ponteiro para pessoa
    Pessoa *p = (Pessoa *)malloc(sizeof(Pessoa)); // malloc para alocar memoria
    if (p == NULL)
        return 1;

    printf("digite sua seu nome:");
    scanf("%s", p->nome); // usamos setas

    printf("digite sua idade : ");
    scanf("%d", &p->idade);

    printf("%s tem %d anos.\n", p->nome, p->idade);

    free(p);
    return 0;
}