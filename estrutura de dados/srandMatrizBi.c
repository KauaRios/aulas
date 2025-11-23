#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//como criar uma matriz

int main(){
    //tipo identificador
    


    int i,j, mat1[3][3]={1,2,3,4,5,6,7,8,9};
    /*      c0 c1 c2
    Linha 0  1  2  3
    Linha 1  4  5  6
    Linha 2  7  8  9
    */

    srand(time(NULL));

    for(i=0; i<3; i++){
        for(j=0; j<3 ; j++){
            mat1[i][j]=rand();
        }
    }
//imprimir Matriz
    for(i=0; i<3; i++){
        for(j=0; j<3 ; j++)
            printf("%d ",mat1[i][j]);
        printf("\n");
    }










    return 0;
}
