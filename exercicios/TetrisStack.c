#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>





#define PECAS_MAX 10

typedef struct{
    int id;
    char nome[20];
}Elemento;



typedef struct{
    Elemento itens[PECAS_MAX];
    int inicio;
    int fim;
    int total;

}Fila;

void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;

}
int FilaCheia(Fila *f) {
    return f->total == PECAS_MAX;
}

int FilaVazia(Fila *f) {
    return f->total == 0;
}



Elemento Retirar(Fila *f){
    Elemento vazio = {-1,""}; // Valor padrão caso a fila esteja vazia
    if(FilaVazia(f)) return vazio; // Evita remoção se estiver vazia
    Elemento e = f->itens[f->inicio]; // Armazena o item a ser removido
    f->inicio = (f->inicio + 1) % PECAS_MAX; // Atualiza o índice de início
    f->total--; // Diminui o total
    return e; // Retorna o item removido
}

void Inserir(Fila *f, Elemento e){
    if(FilaCheia(f)) return;
    f->itens[f->fim] = e;
    f->fim = (f->fim + 1) % PECAS_MAX;
    f->total++;
}


void exibirFila(Fila*f){
    printf("FIla: \n");
    for(int i=0;i<f->total;i++){
        int indice = (f->inicio + i) % PECAS_MAX;
        printf("Elemento %d: ID: %d, Nome: %s\n", i, f->itens[indice].id, f->itens[indice].nome);

    }
    printf("\n");
}

void gerarpeca(Elemento *e,int id,char tipo){
    e->id=id;
    sprintf(e->nome,"Peca_%c",tipo);
}







int main(){
    srand(time(NULL));
    char tipo[]={'I','O','T','L'};
    Fila fila;
    inicializarFila(&fila);

   for(int i=0;i<5;i++){
        Elemento e;
        gerarpeca(&e,i+1,tipo[rand()%4]);
        Inserir(&fila,e);
    }


    printf("Digite Uma opcao: \n1-Remover Peca\n2-Inserir Peca  \n3-Exibir Fila \n4-Sair\n");
    int opcao;
    do{
        printf("Opcao: ");
        scanf("%d",&opcao);
        switch (opcao){
            case 1:{
                Elemento removido=Retirar(&fila);
                if(removido.id==-1){
                    printf("Fila Vazia.Nao e possivel remover \n");
                } else{
                    printf("Peca Removida : ID: %d , Nome: %s\n",removido.id,removido.nome);
                }
                break;
            }
            case 2:{
                if(FilaCheia(&fila)){
                    printf("Fila Cheia.Nao e possivel inserir nova peca \n");
                } else{
                    Elemento e;
                    static int proximoID=PECAS_MAX+1; //continuar ids das peças iniciais
                    gerarpeca(&e,proximoID++,tipo[rand()%4]);
                    Inserir(&fila,e);
                    printf("Peca inserida: ID: %d, Nome: %s\n",e.id,e.nome);
                }
                break;
            }
            case 3:{
                exibirFila(&fila);
                break;
            }
            case 4:{
                printf("Saindo...\n");
                break;
            }
            default:{
                printf("Opcao Invalida.Tente Novamente \n");
                break;
            }
        }
    } while (opcao !=4);
    
    return 0;
}

//void inserir(Fila *f, Elemento e) {
   // if (filaCheia(f)) // Impede inserção se estiver cheia
   //    // return;
  //  f->itens[f->fim] = e;            // Insere no final
   // f->fim = (f->fim + 1) % MAX;     // Atualiza circularmente o índice
   // f->total++;                      // Incrementa a contagem de elementos
    //int main() {


 //}









//*Elemento retirar(Fila *f) {
 //   Elemento vazio = {-1};               // Valor padrão caso a fila esteja vazia
 //   if (filaVazia(f)) 
      //  return vazio;      // Evita remoção se estiver vazia
   // Elemento e = f->itens[f->inicio];    // Armazena o item a ser removido
 //   f->inicio = (f->inicio + 1) % MAX;   // Atualiza o índice de início
  //  f->total--;                          // Diminui o total
 //  return e;                            // Retorna o item removido
    //}