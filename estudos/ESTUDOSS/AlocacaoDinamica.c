#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct No{
    int cod;
    char nome[10];
}No;



int main(){
    No *p=(No*)malloc(sizeof(No));
     

    if(p==NULL){
        printf("Erro ao alocar memoria");
         system("pause");
        exit(0);

    }else{
        printf("Insira o codigo: \n");
        scanf("%d",&p->cod);
        fflush(stdin);
    
        
            printf("Insira o nome: \n");
            scanf("%s",&p->nome);
            fflush(stdin);



            system("pause");//getch()

            system("cls");//systeam clear
            
         printf("Codigo %d - nome: %s\n",p->cod,p->nome);
         free(p);
    }
    













    return 0;
}