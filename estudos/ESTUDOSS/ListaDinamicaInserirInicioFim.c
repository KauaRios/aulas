#include <stdio.h>
#include <stdlib.h>



typedef struct No{
    int valor;
    struct No*proximo;
    

}No;


typedef struct Lista{
  
    No *ini;
    No *fim;
}Lista;



Lista l;


void insereInicio(int elemento){
    No*ptr=(No*)malloc(sizeof(No));
    ptr->valor=elemento;
    ptr->proximo=NULL;


    if(l.ini==NULL){
        l.fim=ptr;
    }else{
        ptr->proximo=l.ini;
       

    }
    l.ini=ptr;





}


void insereFim(int elemento){
No*ptr=(No*)malloc(sizeof(No));
ptr->valor=elemento;
ptr->proximo=NULL;

if(l.ini==NULL){
    l.ini=ptr;
    l.fim=ptr;
}else{
    l.fim->proximo=ptr;
    l.fim=ptr;
}








}

void Liberatudo(){
    No*ptr=l.ini;
    while(ptr!=NULL){
       No*aux=ptr;
       ptr->proximo;


       //libera memoria
       free(aux->valor);
       free(aux);
       
    }
    l.ini=NULL;
    l.fim=NULL;


}

void imprime(){
    No*ptr=l.ini;
    printf("Inicio-> ");
    while(ptr!=NULL){
        printf("%d->",ptr->valor);
        ptr=ptr->proximo;
}
printf(" <-Fim");
}

int main(){



int valor;
l.ini=NULL;
l.fim=NULL;
    insereInicio(10);
    insereInicio(20);
    insereInicio(30);
    imprime();
    system("pause");
    insereFim(40);
    insereFim(50);
    insereFim(60);
    imprime();
    system("pause");







    return 0;
}