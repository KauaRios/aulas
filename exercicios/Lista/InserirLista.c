#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct Lista {
    No* ini;
    int tam;
} Lista;

Lista l;

void InserirInicio(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria\n");
        return;
    }

    novo->valor = valor;
    novo->proximo = l.ini;
    l.ini = novo;
}

void RemoverInicio() {
    if (l.ini == NULL) {
        printf("Lista Vazia\n");
        return;
    }

    No* ptr = l.ini;
    l.ini = l.ini->proximo;
    free(ptr);
}

void imprime() {
if(l.ini==NULL){
    printf("Lista Vazia\n");
    return;
}
   

    No* ptr = l.ini;
    while (ptr != NULL) {
        printf("%d -> ", ptr->valor);
        ptr = ptr->proximo;
    }
    printf("NULL\n");
}


void Liberatudo() {
    No* ptr = l.ini;
    while (ptr != NULL) {
        No* aux = ptr;
        ptr = ptr->proximo;
        free(aux);
    }
    l.ini = NULL;
}


int buscaLinearLista(int valor){
    int pos=0;//um contador para sabermos a posiçao do indice
    No*atual=l.ini; //ponteiro que vai passar pelos elementos

    //enquanto nao chegarmos ao fim da lista null
    while(atual!=NULL){
        //verificamos se o dado do nó atual é o que procuramos
        if(atual->valor==valor){
        return pos;
        }
    
    //se nao for pulamos para o próximo nó
    atual=atual->proximo;
    pos++;

}
//se o while acabar ,significa que percorremos toda a lista e nao achamos 
return -1;
}

int main() {
    l.ini = NULL;

    InserirInicio(10);
    imprime();
    system("pause");

    InserirInicio(20);
    imprime();
    system("pause");

    InserirInicio(30);
    imprime();
    system("pause");

    RemoverInicio();
    imprime();
    system("pause");

    Liberatudo();

    return 0;
}
