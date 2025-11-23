#include <stdio.h>
#include <stdlib.h>




//struct para um item da lista que possui um inteiro



struct ElementoLista{
    int valor;
    struct ElementoLista*proximo;
};



//define um novo tipo de dados (Item)
typedef struct ElementoLista Item;


//prototipos
void imprime(Item *cabeca);
void insereFim(Item*cabeca,int valor);
void libera(Item*cabeca);









int main(){
Item cabeca;
cabeca.proximo=NULL;  //vazia aponta para nada


printf("\n Inserindo Itens novos na lista");
insereFim(&cabeca,15);
insereFim(&cabeca,125);
insereFim(&cabeca,155);



//aguarda o usuario pressionar algo

system("PAUSE");



//uma funcao para imprimir os itens da lista


printf("\nImprimindo Itens da Lista\n");
imprime(&cabeca);

system("PAUSE");


printf("\nLiberando Memoria dos Itens Da lista...\n");
libera(&cabeca);

system("PAUSE");


    return 0;
}
void insereFim(Item*cabeca,int valor){
//cria um ponteiro para o novo item e aloca dinamicamente 
Item*novo=(Item*)malloc(sizeof(Item));

//inicializa o novo item
novo->proximo= NULL;   //se torna ultimo da lista
novo->valor=valor; // conteudo item

printf("Item de valor %3d alocado na posicao  %p\n" , novo->valor,novo);

Item * atual=cabeca;
while(atual->proximo !=NULL){
    atual=atual->proximo;
}
//checando na ultima posicao,colocando ponteiro pro 
atual->proximo=novo;


}

//funcao para imprimir elementos

void imprime(Item *cabeca){
    //este item aponta para o atual
    //como o item do inicio eh cabeca,a  impressao comeca no proximo item
    Item*atual=cabeca->proximo;


    //laco executa até o ultimo item
    int i=0;
    while(atual!=NULL){
        printf("Valor do item : %3d\n",atual->valor);
        i++;
        //faz atual mover para o proximo item
        atual=atual->proximo;
        
    }
    printf("total de itens na lista : %d\n",i);

}
void libera(Item*cabeca){
    //ponteiro para o inicio da lista
Item*atual=cabeca->proximo;
//ponteiro para item a ser liberado
Item*aux;

//parte do inicio da lista,eliminando todos os Itens
while(atual!=NULL){
    //o aux recebe o endereco do atual a ser liberado
    aux=atual;
    //o atual recee o endereco do proximo elemento a ser liberado

    atual=atual->proximo;

    printf("Liberando Memoria %3d na posicao %p\n",aux->valor,aux);
    free(aux);



    }


}

