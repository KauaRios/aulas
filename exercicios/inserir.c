#include <stdio.h>
#include <stdlib.h>



typedef struct no{
    int valor;
    struct no*proximo;
}No;



typedef struct {
    No *inicio;
    int tam;
}Lista;



void criar_lista(Lista *lista){
    lista->inicio=NULL;
    lista->tam=0;
}



void inserir_inicio_lista(Lista *lista,int num){
    No *novo= malloc(sizeof(No));



    if(novo){
        novo->valor=num;
        novo->proximo=lista->inicio;
        lista->inicio=novo;
        lista->tam++;



    }else
        printf("Erro ao alocar memoria ! \n");

}

void imprimir_lista(Lista lista){
    No *no=lista.inicio;
    printf("Lista tam  %d:",lista.tam);
    while(no){
        printf("%d",no->valor);
        no=no->proximo;
    }

}




int main(){
    Lista lista;
    criar_lista(&lista);
    inserir_inicio_lista(&lista,10);
    imprimir_lista(lista);
    inserir_inicio_lista(&lista,20);
    imprimir_lista(lista);

    

}