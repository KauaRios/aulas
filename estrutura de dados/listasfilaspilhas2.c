#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int chave;
} Item;


typedef struct{
    
    Item *v;
   size_t n,cap;
    
} Lista;

static void lista_init(Lista * L ){
    L->v=NULL;
    L->n=0;
    L->cap=0;
    
}


static void lista_free(Lista * L){
    free(L->v);
    L->v=NULL;
    L->n=L->cap=0;
}
int inserir(Lista *L ,Item  x){
    if (L->n == L->cap){
        size_t nova=L->cap ? L->cap * 2 : 4;
        Item *p =(Item *)realloc(L->v,nova*sizeof * p);
        if(!p)
        return -2;
        L->v=p;
        L->cap=nova;
    }
    L->v[L->n++]=x;
    return 1;
}

int main (void){
    Lista L;
    lista_init(&L);
    
    inserir(&L,(Item){.chave=10});
    inserir(&L,(Item){.chave=20});
    inserir(&L,(Item){.chave=30});
    
    for(size_t i=0;i<L.n;++i)
        printf("%d",L.v[i].chave);
        puts("");
        
        lista_free(&L);


    return 0;
}
