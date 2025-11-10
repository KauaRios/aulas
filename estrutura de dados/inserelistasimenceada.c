#include <stdio.h>
#include <stdlib.h>



//estrutura basica de uma lista
typedef struct No{
    int valor;
    struct No *proximo;

}No;
//procedimento para inserir
void inserir_no_inicio(No **lista,int num){
    No *novo = malloc(sizeof(No));


    if(novo){
        novo->valor=num;
        novo->proximo= *lista;
        *lista=novo;

    }
    else
        printf("Erro ao alocar Memoria \n");



}


//procedimento para inserir no fim
void inserir_fim_lista(No **lista,int num){
    No *aux,*novo=malloc(sizeof(No));


    if(novo){
        novo->valor=num;
        novo->proximo=NULL;
        //é o primeiro?
        if(*lista==NULL)
            *lista=novo;
        else{
            aux=*lista;
            while(aux->proximo)
                aux=aux->proximo;
            aux->proximo=novo;

            }

    }else
        printf("Erro ao Alocar Memoria");
        /*Entendendo o else

O else indica que a lista não está vazia, ou seja, já existe pelo menos um elemento dentro dela.

Então o que queremos fazer aqui é:
➡️ ir até o último nó
➡️ conectar o novo nó (novo) ao final da lista.

3. Linha a linha:
aux = *lista;

Aqui criamos um ponteiro auxiliar chamado aux, que começa apontando para o primeiro nó da lista.

Lembre que lista é um ponteiro para ponteiro (No **lista), então *lista é o endereço do primeiro nó.
Logo, aux agora serve para percorrer a lista.

while (aux->proximo)

Essa linha significa:

Enquanto o próximo nó (proximo) não for NULL, continue andando.

O operador -> acessa um campo dentro do struct para o qual aux aponta.
Então aux->proximo é o ponteiro para o próximo nó.

Quando aux->proximo for NULL, isso quer dizer que chegamos ao último nó da lista.

aux = aux->proximo;

Dentro do while, avançamos para o próximo nó.
É como dizer: “anda um passo à frente na fila”.

Esse laço vai repetir até chegarmos no último nó — aquele cujo proximo é NULL.

aux->proximo = novo;

Agora que aux aponta para o último nó, nós fazemos ele apontar para o novo nó que queremos adicionar.

Ou seja:

O antigo último nó agora aponta para o novo nó.
E o novo nó passa a ser o novo último da lista*/


    




}
    








int main(){





    return 0;
}