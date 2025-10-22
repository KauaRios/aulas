#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int chave;
} Item;


int buscar(const Item lista[],int n, int chave){
 for (int i=0; i<n;i++){
 if(lista[i].chave==chave)
 return i;
 }
 return -1;
 }
 int main(void) {
     Item v[5]={{5},{8},{13},{21},{34}};
     int n=5;
     
     printf("Buscar 21 -> %d\n",buscar(v,n,21));
      printf("Buscar 99 -> %d\n",buscar(v,n,99));


    return 0;
}
