#include <stdio.h>
#include <stdlib.h>


        // Como ler uma Matriz A partir de lo teclado

int main(){
int i , j , mat[3][3]= {1,2,3,4,5,6,7,8,9};


for(i=0; i<3; i++){
    for(j=0;j<3;j++){
        printf("Digite um valor %d %d:",i,j);
        scanf("%d",&mat[i][j]);
    }
}


for(i=0; i<3;i++){
    for(j=0;j<3;j++)
        printf("%d ",mat[i][j]);
    printf("\n");

}







return 0;
}
