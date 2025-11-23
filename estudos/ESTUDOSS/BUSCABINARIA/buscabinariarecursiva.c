#include <stdio.h>
#include <stdlib.h>








int buscaBinariaRecursiva(int vetor[],int inicio,int fim,int valor){
    //se a area de busca se torna invalida 
    //o elemento nao existe
    if(inicio>fim){
        return -1;
    }


    //calcula posiçao do  meio 
    //usa inicio +(fim-inicio )/2 é mais seguro contra overflow
    int meio=inicio+(fim-inicio)/2;



    //se o elemento do meio é o que procuramos,encontramos
    //este é outro valor de caso BASE(sucesso)
    if(vetor[meio]==valor){
        return meio;
    }




    //passo recursivo
    //se o elemento do meio for menor que o valor delegamos a busca
    //para metade direita do valor
    else if(vetor[meio]<valor){
        return buscaBinariaRecursiva(vetor,meio+1,fim,valor);
    }
    //caso contrario,delegamos a busca para metade esquerda
    else{
        return buscaBinariaRecursiva(vetor,inicio,meio-1,valor);
    }
    
}
