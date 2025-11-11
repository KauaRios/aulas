#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int dia,mes,ano;
}Data;


typedef struct p
{
    char nome[50];
    Data data;
   
}Pessoa;






typedef struct no{
    Pessoa p;
    struct no *proximo;
}No;


typedef struct{
No *topo;
int tam;
}Pilha;

void criar_pilha(Pilha *p){
    p->topo=NULL;
    p->tam=0;
}



Pessoa ler_pessoa(){
    Pessoa p;

    printf("\nDigite seu nome e data de nascimento dd mm aaaa:\n");
    scanf(" %49[^\n]", p.nome);
    scanf("%d%d%d", &p.data.dia, &p.data.mes, &p.data.ano);

    return p;
}
void imprimir_pessoa(Pessoa p){
    printf("\nNome: %s\nData: %2d/%2d/%4d\n",p.nome,p.data.dia,p.data.mes,p.data.ano);


}
 void push(Pilha *p){
    No *novo=malloc(sizeof(No));

    if(novo){
        novo->p=ler_pessoa();
        novo->proximo=p->topo;
        p->topo=novo;
        p->tam++;
        
       
    }else{
        printf("\nErro Ao Alocar Memoria ! ");
        
    }

} 

No* pop(Pilha *p){
    if(p->topo){
        No*remover=p->topo;
        p->topo=remover->proximo;
        p->tam--;
        return remover;
    }else{
        printf("\nPilha Vazia!\n");
        return NULL;
    }
}

void imprimir_pilha(Pilha *p){
    No *aux=p->topo;
    printf("===========PILHA TAM: %d=============",p->tam);
    while(aux){
        imprimir_pessoa(aux->p);
        aux=aux->proximo;
    }
    printf("================FIM DA PILHA=============");

}


int main(){
    int opcao;
    No *remover;
    Pilha p;
    criar_pilha(&p);

do{
    printf("\n0 -Sair\n1 -Empilhar\n2 -Desempilhar\n3 - Imprimir\n");
    scanf("%d", &opcao);

   
    switch(opcao){

        case 1:
        push(&p);
        break;

        case 2:
        remover=pop(&p);
        if(remover){
            printf("Elemento removido com sucesso\n");
            imprimir_pessoa(remover->p);
            free(remover);
        }else 
            printf("Sem No A remover !");
        break;

        case 3:
        imprimir_pilha(&p);
        break;

        case 0:
        printf("Saindo...\n");
        break;

        default:
        printf("Opcao invalida!\n");
        break;
  
    }
        


}while (opcao!=0);



    return 0;

}
