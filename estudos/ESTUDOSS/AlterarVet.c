
#include <stdio.h>
#include <stdlib.h>


int main()
    //alterar conteudo de um vetor :

int i;
int num2[10];

for(i=0; i<10; i++){
    printf("Digite o elemento da posicao %d:",i);
    scanf("%d", &num2[i]);
}
for(i=0; i<=10;i++)
   num2[i]=num2[i] * 3;

printf("\n\n");
for(i=0; i <10 ; i++){
    printf("%d ",num2[i]);

}
printf("\n\n");


return 0;
}
