#include <stdio.h>
#include <stdlib.h>





//Descrição ordena um vetor de inteiros em ordem crescente usando o algoritmo de
//inserçao
void InsertionSort(int vetor[],int tamanho){

//começamos do segundo elemento(indice 1) , pois o primeiro já está ordenado

for(int i=1;i<tamanho;i++){
    //pegamos a carta da vez e guardamos na nossa chave
    int chave=vetor[i];
    int j =i -1;

    //agora olhamos para a mao (a parte ordenada a esquerda)
    //enquanto houver elementos para tras(j>>=0) e o elemento da mao
    //for maior que a nosssa chave
    while(j>=0 && vetor[j]>chave){
        //empurramos o elemento da mao para uma posiçao a direita
        vetor[j+1]=vetor[j];
        j--; //e olhamos para a proxima carta na mao , para tras
    }
    // o loop while parou .encontramos o lugar certo 
    //inserimos a nossa chave no espaço que foi aberto
    vetor[j+1]=chave;

}


}