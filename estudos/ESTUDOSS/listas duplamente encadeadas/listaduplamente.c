#include <stdio.h>
#include <stdlib.h>
//lista duplamente encadeada


typedef struct No{
    int valor;
    struct No*proximo;
    struct No*anterior;
    

}No;



typedef struct lista{
    No*ini;
    No*fim;
}Lista;

Lista  l;


void inicializarLista(){
    l.ini=NULL;
    l.fim=NULL;
}




void inserirInicio(int elemento){
   
    No*novo=(No*)malloc(sizeof(No)); //alocaçao dinamica de memoria
    novo->valor=elemento;
    novo->proximo=NULL;
    novo->anterior=NULL;


    if(l.ini==NULL){
        l.ini=novo;
        l.fim=novo;
    }else{
        novo->proximo=l.ini; //liga novo -> antigo primeiro
        l.ini->anterior=novo; //liga antigo novo
        novo->anterior=NULL; //novo é o primeiro da lista
        l.ini=novo;  //lista passa a apontar para o novo inicio
/*O novo nó deve apontar para o antigo início.

O antigo início deve apontar para trás, para o novo.

O novo início não tem anterior (então NULL).

A lista passa a começar pelo novo nó.*/
}
}


void inserirFim(int elemento){
    No*novo=(No*)malloc(sizeof(No));
    novo->valor=elemento;
    novo->proximo=NULL;
    novo->anterior=NULL;

    if(l.ini==NULL){
        l.ini=novo;
        l.fim=novo;
    }else{
        l.fim->proximo=novo;
        novo->anterior=l.fim;
        l.fim=novo;
    }


}

void inserir_no_meio(int elemento,int ant){
    No*novo=(No*)malloc(sizeof(No));
    novo->valor=elemento;
    

    if(l.ini==NULL){
        novo->proximo=NULL;
        novo->anterior=NULL;
        l.ini=novo;
        l.fim=novo;

}else{
    No*atual=l.ini;
   while (atual != NULL && atual->valor != ant){
        atual=atual->proximo;
    }
    if(atual==NULL){
       printf("Valor %d nao encontrado Na lista",ant);
       free(novo);
       return;
    }

    //conecta o novo no da lista
    novo->proximo=atual->proximo;
    novo->anterior=atual;
      

        if(atual->proximo!=NULL){
            novo->proximo->anterior=novo;
        }else{
            l.fim=novo;
        }
        atual->proximo=novo;
    
        

        

    }



    }





