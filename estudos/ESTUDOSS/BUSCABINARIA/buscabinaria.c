#include <stdio.h>
#include <stdlib.h>



int buscaBinaria(int vetor[],int tamanho,int valor){
int inicio;
int fim=tamanho-1;


while(inicio<=fim){
    //int meio =(inicio+fim)/2 forma comum , mas pode dar overflow com numeros grandes

    //forma mais segura
    int meio=inicio+(fim-inicio)/2;


    // se o valor estiver exatamente no meio encontramos
    if(vetor[meio]==valor){
        return meio; //encontramoss retorna o indice
    }
    // se o valor no meio for menor que o buscado
    //significa que o nosso alvo so pode estar na metade direita(maior)
    else if(vetor[meio]<valor){
        inicio=meio+1;// descartamos a metade esquerda
    }
    // se o valor do meio for maior que o buscado
    //significa que o nosso alvo so pode etar na metade esquerda (menor)
    else{
        fim=meio-1;//descartamos metade direita;
    }
}
//se o loop terminar ,significa que 'inicio' ultrapassou fim
//e o valor nao foi encontrado
return -1;
}