#include <stdio.h>
#include <stdlib.h>


typedef int Elemento;



typedef struct No{
    Elemento elemento;
    struct No* prox;
} No;


typedef struct{
    No *inicio;//null =vazia
    No *fim; //NULL=vazia
    size_t tam;//opcional   
}Fila;


void fila_init(Fila *f){
    f->inicio= f->fim = NULL;
    f->tam=0;
}

int enfileirar(Fila *f,Elemento e){           
    No *novo= (No*) malloc (sizeof *novo);  
                                        
    if(!novo)
    return 0; //falha alocacao
    novo->elemento=e;
    novo->prox=NULL;

    if(f->fim){                 //havia elementos
    f->fim->prox=novo;          //liga antigo fim ao novo
}else{                          //fila vazia                           
    f->inicio=novo;
}
f->fim=novo;
f->tam++;
return 1; //sucesso
}


void fila_dump(const Fila *f){
    const No *p=f->inicio;
    printf("Fila(%zu): [",f->tam);
    while(p){
        printf("%d",p->elemento);
        p=p->prox;
        if(p)
        printf("->");
    }
    puts("]");
}

void fila_clear(Fila *f){
    No *p=f->inicio;
    while(p){
        No *nx=p->prox;
        free(p);
        p=nx;
    }
    f->inicio=f->fim=NULL;
    f->tam=0;
}





int main(void){
    Fila F;
    fila_init(&F);

    int dados[] ={10,20,30,40,50};
    for (size_t i = 0; i < sizeof dados / sizeof *dados; i++) {
        if(!enfileirar(&F,dados[i])){
            puts("Falha de Memoria ao enfileirar");
            break;
        }
        fila_dump(&F);
    }


    fila_clear(&F);
    return 0;

}