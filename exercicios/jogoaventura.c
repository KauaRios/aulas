#include <stdio.h>
#include <stdlib.h>
#include <string.h>//biblioteca para funçoes strcpy e strcmp





#define MAX_STR_LEN 50
#define MAX_TAM 10






typedef struct{
    char dados[MAX_TAM][MAX_STR_LEN];// Matriz 10 linhas (itens), 50 colunas(caracteres item)
    int quantidade;
}ListaEstatica;


//funçoes da lista Estatica

//esta funçao prepara a lista para ser usada
//ela simplesmente define o contador quantidade 0, indicando o qque a lista esta vazia
//recebemos um ponteiro lista para modificar a variavel original passada para a funçao


void inicializarListaEstatica(ListaEstatica *lista);

void inserirListaEstatica(ListaEstatica *lista,const char* texto);
void removerListaEstatica(ListaEstatica*lista,const char* texto);
void listarListaEstatica(const ListaEstatica *lista);