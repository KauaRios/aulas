#include <stdio.h>
#include <stdlib.h>


typedef struct No{
    int valor;
    struct No*proximo;
}No;


typedef struct Lista{
    No*ini;
    
}Lista;

Lista l;



void inserirInicio(int elemento){
No*novo=(No*)malloc(sizeof(No));
novo->valor=elemento;
novo->proximo=NULL;


if(l.ini==NULL){
    l.ini=novo;
}else{
    novo->proximo=l.ini;
    l.ini=novo;
}



}

void imprime(){
    No*ptr=l.ini;

    while(ptr!=NULL){
        printf("%d->",ptr->valor);
        ptr=ptr->proximo;

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
  


}






    









int main(){
int valor;
l.ini=NULL;


inserirInicio(10);
imprime();
system("pause");
inserirInicio(20);
imprime();
system("pause");

inserirInicio(30);
imprime();
system("pause");
inserirInicio(40);
imprime();
system("pause");
inserirInicio(50);
imprime();
system("pause");
imprime();







    return 0;
}