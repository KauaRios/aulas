#include <stdio.h>
#include <stdlib.h>

//descrição recebe o endereço de duas variavéis inteiras e troca os valores entre elas
//por usar ponteiros (int*),a funçao modifica variaveis originais que foram
//passadas e ela

void trocar(int *a,int *b){
    //1 guarda o valor apontado por 'a' em uma variavel temporária
    //o asterisco é o operador de "desferencia",que acessa o valor do endereço


    int temp=*a;



    //valor apontado por 'b' é copiado para o local apontado por a
    *a=*b;


    *b=temp;
}



