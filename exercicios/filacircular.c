#include <stdio.h>

typedef struct{
    int v[5];
    int inicio,fim,qtd;

}Fila;


void fila_init(Fila*f){
    f->inicio = 0;
    f->fim = 0;
    f->qtd = 0;
}





int fila_vazia(Fila*f){
    return f->qtd == 0;
}

int fila_cheia(Fila*f){
    return f->qtd==5;
}

int enfileirar(Fila*f,int valor){
    if(fila_cheia(f)){
        return 0;
    }
    f->v[f->fim] = valor;
    f->fim = (f->fim + 1) % 5;
    f->qtd++;
    return 1;
}



int desenfileirar(Fila*f,int *valor){

    if(fila_vazia(f)){
        return 0;
    }
    *valor = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % 5;
    f->qtd--;
    return 1;
}

void mostrar(Fila*f){
    if(fila_vazia(f)){
        printf("Fila vazia.\n");
        return;
    }
    printf("Elementos da fila:\n");
    int i = f->inicio;
    for(int count = 0; count < f->qtd; count++){
        printf("%d\n", f->v[i]);
        i = (i + 1) % 5;
    }
}






int main(){
    Fila f;
    fila_init(&f);
    enfileirar(&f,10);
    enfileirar(&f,20);
    enfileirar(&f,30);
    enfileirar(&f,40);
    enfileirar(&f,50);
    mostrar(&f);
    int valor;
    desenfileirar(&f,&valor);
    printf("Desenfileirado: %d\n",valor);
    mostrar(&f);
    





    return 0;
}