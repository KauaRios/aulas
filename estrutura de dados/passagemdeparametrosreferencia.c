#include <stdio.h>
// a funçao agora recebe um endereço de ponteiro para int
void dobrar(int * x){
    //acessamos o valor e modificamos
    *x=(*x) * 2;




}


int main(){



int numero=5;

printf("Antes da funçao, o valor é = %d\n",numero);//5

//passamos o endereço com operador & e nao o valor, isso é o diferente da passagem de parametros por valor
dobrar(&numero);


printf("Depois da funçao o valor é = %d\n",numero);//10 e nao mais 5 como na passagem por valor


return 0;
}