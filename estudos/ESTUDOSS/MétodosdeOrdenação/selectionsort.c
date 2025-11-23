#include <stdio.h>
#include <stdlib.h>




//descriçao ordena um vetor de inteiros em ordem crescente usando o
//algoritmo de ordenaçao por seleção

void selectionSort(int vetor[],int tamanho){
    //laço externo percorre as posições que precisam ser prenchidas
    //uma de cada vez ,da esquerda para direita
    for(int i=0;i<tamanho;i++){
        //asume o que o menor ,por enquanto , é o elemento na posição i
        int indiceMenor=i;


        //laço externo busca pelo menor elmento no resto do vetor(a direita de i)
        for(int j=i+1;j<tamanho;j++){
            if(vetor[j]<vetor[indiceMenor]){
                //atualiza o indice menor
                indiceMenor=j;
            }

        }


        //apos o laço interno,indice menor contem a posição do menor elemento
        //se o menor nao for o proprio elemento 
        //realiza a troca

        if(indiceMenor !=i){
            trocar(&vetor[i],&vetor[indiceMenor]);
        }
    }
}