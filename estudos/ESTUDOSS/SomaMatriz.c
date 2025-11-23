#include <stdio.h>
#include <stdlib.h>


        // Como alterar O conte�do de Uma Matriz

int main(){
int i , j , mat[3][3]= {11,12,13,14,15,16,17,18,19},mat2[3][3]= {1,2,3,4,5,6,7,8,9},mat3[3][3]={};


for(i=0; i<3; i++){
    for(j=0;j<3;j++){
        mat3[i][j]= mat[i][j]+mat2[i][j];

    }
}
for(i=0; i<3;i++){
    for(j=0;j<3;j++)
        printf("%2d ",mat3[i][j]);
    printf("\n");

}

return 0;
}
