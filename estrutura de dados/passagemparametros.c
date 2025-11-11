#include <stdio.h>
#include<stdlib.h>







void alteraValor(int *valor);



int main(){
    int valor=10;


    printf("VALOR ANTES DA FUNÇAO %d\n",valor);
    alteraValor(&valor);
    printf("VALOR APOS A FUNCAO %d\n",valor);


return 0;
}


void alteraValor(int *valor){
    *valor=*valor*2;
    printf("VALOR DE DENTRO DA FUNCAO %d\n",*valor);
}