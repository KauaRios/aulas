#include <stdio.h>
#include <stdlib.h>



int main(){

    int vet[10];
    int vet2[10];


int i;


    for( i=0; i<10; i++){
        printf("Digite o elemento %d do Vetor :",i);
        scanf("%d", &vet[i]);
    }

    for( i=0; i<10; i++){
        vet2[i]=vet[i]*2;
    }
       

    


    for(int i=0; i<10; i++){
        printf("Os Valores Armazenados no Vetor %d Foram  : ",i);
        printf("Original: %d  Dobrado: %d\n", vet[i], vet2[i]);

    }





    return 0;
}




