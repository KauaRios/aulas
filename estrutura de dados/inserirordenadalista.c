#include <stdio.h>
#include <stdlib.h>



//estrutura basica de uma lista
typedef struct No{
    int valor;
    struct No *proximo;

}No;
typedef struct{
    No *inicio;
    int tam;
}Lista;

void criar_lista(Lista *lista){
    lista->inicio=NULL;
    lista->tam=0;
}

//procedimento para inserir
void inserir_no_inicio(Lista *lista ,int num){
    No *novo = malloc(sizeof(No));


    if(novo){
        novo->valor=num;
        novo->proximo= lista->inicio;
        lista->inicio=novo;
        lista->tam++;

    }
    else
        printf("Erro ao alocar Memoria \n");



}


//procedimento para inserir no fim
void inserir_fim_lista(Lista *lista,int num){
    No *aux,*novo=malloc(sizeof(No));


    if(novo){
        novo->valor=num;
        novo->proximo=NULL;
        //é o primeiro?
        if(lista->inicio==NULL)
            lista->inicio=novo;
        else{
            aux=lista->inicio;
            while(aux->proximo)
                aux=aux->proximo;
            aux->proximo=novo;

            }
            lista->tam++;

    }else
        printf("Erro ao Alocar Memoria\n");
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


void inserir_no_meio(Lista *lista,int num,int ant){
    No *aux ,*novo =malloc(sizeof(No));

    if(novo){
        novo->valor=num;
        //é o primeiro?
        if(lista->inicio==NULL){
            novo->proximo=NULL;
            lista->inicio=novo;
        }
        else{
            aux=lista->inicio;
            while(aux->valor !=ant && aux->proximo)
                aux=aux->proximo;
            novo->proximo=aux->proximo;
            aux->proximo=novo;

            /*// Se a lista não está vazia, vamos inserir o novo nó depois de um valor específico (ant)
else {
    // 'aux' começa apontando para o primeiro nó da lista
    aux = *lista;

    // Percorre a lista enquanto:
    // - O valor do nó atual for diferente do valor 'ant'
    // - E ainda existir um próximo nó (para evitar acessar NULL)
    while (aux->valor != ant && aux->proximo)

        // Faz o ponteiro 'aux' avançar para o próximo nó da lista
        aux = aux->proximo;

    // Agora 'aux' aponta para o nó que contém o valor 'ant'

    // O novo nó deve apontar para o mesmo lugar que 'aux->proximo' apontava antes
    // Ou seja, o novo nó é inserido ENTRE 'aux' e o próximo nó
    novo->proximo = aux->proximo;

    // Faz o nó atual ('aux') apontar para o novo nó
    // Assim, o encadeamento da lista é mantido corretamente
    aux->proximo = novo;
}
*/



}
lista->tam++;



    }else 
        printf("Erro ao Alocar Memoria\n");



}
void inserir_ordenado(Lista *lista,int num){
    No *aux, *novo=malloc(sizeof(No));

    if(novo){
        novo->valor=num;
           
        //a lista está vazia?
        if(lista->inicio==NULL){
        novo->proximo=NULL;
        lista->inicio=novo;
        }else if(novo->valor < lista->inicio->valor){
                novo->proximo=lista->inicio;
                lista->inicio=novo;

        }
        else{
            aux=lista->inicio;
            while(aux->proximo && novo->valor > aux->proximo->valor){
                aux=aux->proximo;
               
            }
             novo->proximo=aux->proximo;
                aux->proximo=novo;
            
                


        }
        lista->tam++;
    

    }else 
        printf("Erro ao alocar memoria!");
    
}
/*// Função: inserir_ordenado
// Objetivo: inserir um novo elemento (num) na lista de forma ordenada (crescente).
// Parâmetros:
//   - lista: ponteiro para a estrutura que contém o início da lista e seu tamanho.
//   - num: valor inteiro que será inserido na lista.
//
// A função garante que, após a inserção, a lista permanecerá em ordem crescente.
void inserir_ordenado(Lista *lista, int num) {
    No *aux, *novo = malloc(sizeof(No)); // Cria um novo nó e reserva memória para ele.

    // Verifica se a alocação de memória foi bem-sucedida.
    if (novo) {
        novo->valor = num; // Atribui o valor recebido ao campo 'valor' do novo nó.

        // Caso a lista esteja vazia (ou seja, sem nenhum nó ainda).
        if (lista->inicio == NULL) {
            novo->proximo = NULL;       // O novo nó não aponta para ninguém.
            lista->inicio = novo;       // Ele passa a ser o primeiro (e único) nó da lista.
        }

        // Caso o novo valor seja menor que o primeiro elemento da lista.
        // Nesse caso, o novo nó deve ser inserido no início.
        else if (novo->valor < lista->inicio->valor) {
            novo->proximo = lista->inicio; // O novo nó passa a apontar para o antigo primeiro.
            lista->inicio = novo;          // E o início da lista agora é o novo nó.
        }

        // Caso contrário, precisamos procurar a posição correta no meio ou fim da lista.
        else {
            aux = lista->inicio; // Ponteiro auxiliar começa no primeiro nó.

            // Este laço percorre a lista enquanto:
            // 1. Ainda houver um próximo nó (aux->proximo != NULL)
            // 2. E o valor do novo nó for maior que o valor do próximo nó.
            //
            // Isso significa que ainda não encontramos o ponto certo de inserção.
            while (aux->proximo && novo->valor > aux->proximo->valor) {
                aux = aux->proximo; // Avança o ponteiro auxiliar para o próximo nó.
            }

            // Agora 'aux' está parado no nó ANTERIOR ao ponto de inserção.
            // Então fazemos o encadeamento do novo nó entre 'aux' e 'aux->proximo'.
            novo->proximo = aux->proximo; // O novo nó passa a apontar para o nó seguinte.
            aux->proximo = novo;          // E o nó anterior aponta agora para o novo nó.
        }

        lista->tam++; // Incrementa o contador de tamanho da lista (controle lógico).
    }

    // Caso malloc falhe, informamos o erro ao usuário.
    else {
        printf("Erro ao alocar memória para o novo nó.\n");
    }
}
*/




void imprimir(Lista lista){
    No *no=lista.inicio;
    printf("\n\t Lista tam %d:",lista.tam);
    while(no){
        printf("%d ", no->valor);
        no=no->proximo;
    }
    printf("\n\n");
}
    








int main(){
    int opcao,valor,anterior;
    //No *lista=NULL;
    Lista lista;

    criar_lista(&lista);
    do{
        printf("\n\t0 - Sair \n\t1 -InserirI\n\t2 -inserirF\n\t3 -InserirM \n\t4 - InserirOrdenado\n\t5 -Imprimir\n");
        scanf("%d",&opcao);


        switch(opcao){
            case 1:
                printf("Digite um valor : ");
                scanf("%d",&valor);
                inserir_no_inicio(&lista,valor);

                break;


            case 2:
                printf("Digite um valor : ");
                scanf("%d",&valor);
                inserir_fim_lista(&lista,valor);
                break;

            
            case 3:
             printf("Digite um valor  e o valor De referencia: ");
                scanf("%d""%d",&valor,&anterior);
                inserir_no_meio(&lista,valor,anterior);

                
                break;
            
            case 4:
                printf("Digite um valor : ");
                scanf("%d",&valor);
                inserir_ordenado(&lista,valor);


                break;


            case 5:
                imprimir(lista);
                break;
            default:
                if(opcao !=0)
                    printf("Opcao Invalida ! \n");



        }

    }while(opcao!=0);





    return 0;
}