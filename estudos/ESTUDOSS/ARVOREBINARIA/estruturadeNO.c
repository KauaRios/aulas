#include <stdio.h>
#include <stdlib.h>






typedef struct No{
    //armazena o nome ou o valor do nó até 49 caracteres
    char valor[50];

    //ponteiro para o filho à esquerda
    struct No * esquerda;
    // ponteiro para filho a direita
    struct No * direita;

}No;

