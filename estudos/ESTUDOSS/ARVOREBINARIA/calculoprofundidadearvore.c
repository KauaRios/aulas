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



//funçao para calcular profundidade   
//raiz inicial 'alvo' é o no cuja profundidade queremos descobrir
//nivel: nivel atual na recursao (começa com 0 para a raiz)


int profundidade(No*raiz,No*alvo,int nivel){
    if(raiz==alvo)
        return nivel; //se o nó atual é o alvo,retorna o nível atual(profundidade encontrada)

    //procura recursivamente na subáarvore esquerda,aumentando o nível
    int esq=profundidade(raiz->esquerda,alvo,nivel+1);
    if(esq != -1)
    return esq; // se encontrou na esquerda , retorna a profundidade


    //se nao encontrou na esquerda,procura na direita
    return profundidade(raiz->direita,alvo,nivel+1);
    //retorn o valor encontrado à direita (ou -1 se nao estiver lá tambem)
}