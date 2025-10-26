#include <stdio.h>
// a funçao agora recebe um endereço de ponteiro para int
void dobrar(int * x){
    //acessamos o valor e modificamos
    *x=(*x) * 2;




}


int main(){


int numero=5;

printf("Antes da funçao, o valor é = %d\n",numero);

//passamos o endereço com operador &
dobrar(&numero);


printf("Depois da funçao o valor é = %d\n",numero);


    return 0;
}