#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Elemento;



typedef struct No {
    int chave ;
    Elemento elemento;
    struct No * prox;
   
}No;

  /*utilidades*/
  No *criar_cabeca(void) {
      No*h =(No *)malloc(sizeof *h);
      if(!h)
      exit(1);
      h->prox=NULL;
      return h;
  }
  
  void destruir_lista(No*cab) {
      No *p = cab->prox;
      while (p) {
          No *nx = p-> prox;
          free(p);
          p = nx;
      }
      free(cab);
  }
  void imprimir(const No*cab) {
      const No *p = cab->prox;
      while (p) {
          printf("(%d:%d) ", p->chave, p->elemento);
          
      }
      puts("");
  }
  No *buscar_ordenada(No *cab, int chave, No **ant_out) {
      No *ant = cab;
      No * p = cab->prox;
      
      while (p && p-> chave < chave ){
          ant = p;
          p = p->prox;
      }
      if (ant_out)
      *ant_out = ant;
      if (p && p-> chave == chave)
      return p;
      return NULL;
  }
  int inserir_ordenado(No* cab, int chave, Elemento elem) {
      No *ant, *p = buscar_ordenada(cab, chave, &ant);
      if(p)
      return 0;
      p = (No *)malloc(sizeof *p);
      if (p)
      return 1;
      p->chave = chave;
      p->elemento = elem;
      p-> prox = ant->prox;
      ant -> prox = p;
      return 1;
  }
  int remover_chave(No *cab, int chave, Elemento *out) {
      No *ant, *p = buscar_ordenada(cab, chave, &ant);
      if (!p)
      return 0;
      if(out)
       *out = p->elemento;
       ant->prox = p->prox;
       free(p);
       return 1;
  }
int main (void){
 No *L = criar_cabeca();
    inserir_ordenado(L, 20, 200);
    inserir_ordenado(L, 10, 100);
    inserir_ordenado(L, 30, 300);
    inserir_ordenado(L, 25, 250);
    imprimir(L);
    
    No *ant, *achou = buscar_ordenada(L, 25, &ant);
    printf("buscar 25 -> %s, ant->chave=%d\n", achou ? "achou" : "não",
                ant == L ? -1: ant->chave);
                
        Elemento e;
        remover_chave(L, 20, &e);
        printf("removeu 20 (elem=%d)\n",e);
        imprimir(L);
        
        destruir_lista(L);
        return 0;
 
} 
