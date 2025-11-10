#include <stdio.h>
#include <stdlib.h>

// Definição do Nó
typedef struct Node {
    int valor;
    struct Node* proximo;
} Node;

// Definição da Lista
typedef struct {
    Node* inicio; // Ponteiro para o primeiro nó
} Lista;

// Função para criar uma lista vazia
Lista* criarLista() {
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

// ----- COMPLETE A FUNÇÃO ABAIXO -----
void insereInicio(Lista* lista, int valor) {
   
    
   

    // 1. Alocar memória para o novo nó
     Node* NovoNo= (Node*) malloc(sizeof(Node));
    // 2. Verificar se o malloc falhou
if (NovoNo == NULL) {
        printf("Erro ao alocar memória\n");
        return;
    }
    // 3. Preencher o novo nó
  NovoNo->valor=valor;
    // 4. Ligar o novo nó na lista
    NovoNo->proximo= lista->inicio;
    lista->inicio= NovoNo;

}
// -------------------------------------

// Função para imprimir a lista (só para testar)
void imprimirLista(Lista* lista) {
    Node* atual = lista->inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int main() {
    Lista* minhaLista = criarLista();
    
    insereInicio(minhaLista, 10);
    insereInicio(minhaLista, 20);
    insereInicio(minhaLista, 30);
    
    imprimirLista(minhaLista); // Deve imprimir: 30 -> 20 -> 10 -> NULL
    
    // (Lembre-se: em um programa real, precisaríamos de uma função para dar 'free' em todos os nós)
    free(minhaLista);
    return 0;
}
