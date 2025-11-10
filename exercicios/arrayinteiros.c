#include <stdio.h>


void pares (int array[],int tamanho){
    printf("Numeros pares no array:\n");
    for(int i=0; i<tamanho;i++){
        if(array[i]%2==0){
            printf("%d ", array[i]);
        }
    }
    printf("\n");
}





typedef struct{
    int maior;
    int menor;
   
}maiormenor;



void printa(maiormenor resultado){
    printf("Maior: %d\n", resultado.maior);
    printf("Menor: %d\n", resultado.menor);
}

void media_printa(float soma, float media){
    printf("Soma: %.2f\n", soma);
    printf("Media: %.2f\n", media);
}


typedef struct{
    float soma;
    float media;

}media;






int main(){


int array[] = {10, 20, 30, 40, 50,60, 70, 80, 90, 100};
maiormenor resultado;
int maior=array[0];
int menor=array[0];


for(int i=1; i<10;i++){
    if(array[i]>maior){
        maior=array[i];
    }
    if(array[i]<menor){
        menor=array[i];
    }












}
resultado.maior=maior;
resultado.menor=menor;
printf("\n==== RESULTADOS ====\n");
printa(resultado);

media resulmedia;
float soma=0.0;
for(int i=0; i<10;i++){
    soma+=array[i];
}
resulmedia.soma=soma;
resulmedia.media=soma/10.0;
media_printa(resulmedia.soma, resulmedia.media);
printf("====================\n\n");


pares(array,10);







return 0;
}