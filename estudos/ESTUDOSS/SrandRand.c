

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    //como gerar Numeros aleatorios
int i;
int num2[10];


srand(time(NULL));

for(i=0; i<10; i++)
    num2[i] = rand();

printf("\n\n");
for(i=0; i <10 ; i++)
    printf("%d ",num2[i]);
    printf("\n\n");


return 0;
}
