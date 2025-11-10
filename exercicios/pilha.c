#include <stdio.h>

typedef struct {
    int vetor[5];
    int topo;
} Pilha;



void pilha_init(Pilha *p){
    p->topo = -1;
}

int pilha_vazia(Pilha *p){
    return p->topo == -1;
}


int pilha_cheia(Pilha *p){
    return p->topo == 4;
}

int push(Pilha *p,int valor){
    if(pilha_cheia(p)){
        return 0; // Falha ao empilhar
    }
    p->topo++;
    p->vetor[p->topo] = valor;
    return 1; // Sucesso ao empilhar
}

int pop(Pilha *p,int *valor){
    if(pilha_vazia(p)){
        return 0; // Falha ao desempilhar
    }
    *valor = p->vetor[p->topo];
    p->topo--;
    return 1; // Sucesso ao desempilhar
}


void mostrar(Pilha *p){
    if(pilha_vazia(p)){
        printf("Pilha vazia.\n");
        return;
    }
    printf("Elementos da pilha:\n");
    for(int i = p->topo; i >= 0; i--){
        printf("%d\n", p->vetor[i]);
    }
}




int main(){
    Pilha p;
    pilha_init(&p);


    push(&p, 10);
    push(&p, 20);
    push(&p, 30);


    mostrar(&p);

    int valor;
    pop(&p, &valor);
    printf("Valor desempilhado: %d\n", valor);

    mostrar(&p);
}