#include <stdio.h>
#include <stdlib.h>


//como criar uma matriz

int main(){
    //tipo identificador
    int vet[10];


    int i , j, mat1[3][3]={1,2,3,4,5,6,7,8,9}   ,mat2[3][3] = {1,2,3,4,5,6,7},mat3[3][3];
    char mat5[3][4]={'a','b','c','d','e','f','g','h','i','j','k','l'};
    /*      c0 c1 c2
    Linha 0  1  2  3
    Linha 1  4  5  6
    Linha 2  7  8  9
    */

    for(i=0; i<3; i++){
        for(j=0; j<3 ; j++)
            mat3[i][j]=mat1[i][j]+mat2[i][j];
    }
//imprimir Matriz
    for(i=0; i<3; i++){
        for(j=0; j<3 ; j++)
            printf("%d ",mat3[i][j]);
        printf("\n");
    }










    return 0;
}
