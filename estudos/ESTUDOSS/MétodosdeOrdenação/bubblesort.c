#include <stdio.h>
#include <stdlib.h>

void trocar(int *a,int *b){
    //1 guarda o valor apontado por 'a' em uma variavel temporária
    //o asterisco é o operador de "desferencia",que acessa o valor do endereço


    int temp=*a;



    //valor apontado por 'b' é copiado para o local apontado por a
    *a=*b;


    *b=temp;
}


//descrição ordena um vetor de inteiros em ordem crescente usando
//algoritmo bubble sort
void bubblesort(int vetor[],int tamanho){

//laço externo : controla o numero de passadas pelo vetor

//a cada passada 'i' , o iesimo maior elemento borbulha
for(int i=0;i<tamanho-1; i++){

    //laço interno: percorre o vetor comprando pares vizinhos
    //o limite (tamanho -1- i) é uma otimização : ele diminui a cada 
    //passada,pois os maiores elementos já estão fixos no final
    for(int j=0;j<tamanho -1 -i; j++){

        //a condiçao de comparação
        if(vetor[j]>vetor[j+1]){
            //a troca 
            trocar(&vetor[j],&vetor[j+1]);
        }
    }
}
}