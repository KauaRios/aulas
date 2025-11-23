#include <stdio.h>




int main(){

int i;

int num2[10];


for(i=0; i<10; i++){
    printf("Digite o elemento da posicao %d:",i);
    scanf("%d", &num2[i]);
}
printf("\n\n");
for(i=0; i <10 ; i++){
    printf("%d ",num2[i]);

}
printf("\n\n");





return 0;
}
