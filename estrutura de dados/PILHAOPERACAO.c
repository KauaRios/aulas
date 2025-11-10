#include <stdio.h>
#include <stdlib.h>




typedef struct lista{
    int dado;
    struct lista *prox;
}celula;


void imprimir();
void push(int);
void pop();



celula *topo = NULL;









int main(){
    push(10);
    push(20);
    push(30);
    imprimir();
    pop();
    imprimir();
    pop();
    imprimir();
    pop();
    imprimir();
    return 0;








}


void push(int item){
    printf("==============================\n");
    printf("=============EMPILHANDO %d ======\n");
    celula *nova = (celula *)malloc (sizeof(celula));
    nova->dado = item;
    nova->prox=topo;
    topo=nova;
    printf("\nValor %d Empilhado",nova->dado);
    printf("\n==============================\n");

}

void pop(){
    printf("==============================\n");
    printf("=============DESEMPILHANDO ======\n");
    if(topo == NULL){
        printf("Pilha Vazia\n");
    }else{
        celula *temp;
        temp=topo;
        topo=topo->prox;
        printf("\nValor %d Desempilhado",temp->dado);
        free(temp); 

    }
    printf("\n==============================\n");

}

void imprimir(){
    printf("==============================\n");
    printf("=============IMPRIMINDO PILHA ======\n");
    if(topo == NULL){
        printf("Pilha Vazia\n");
    }else{
        celula *temp;
        temp=topo;
        while(temp != NULL){
            printf("\nValor: %d",temp->dado);
            temp=temp->prox;
        }
    }
    printf("\n==============================\n");

}