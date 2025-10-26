#include <stdio.h>
//esta funçao recebe copia do valor
void dobrar(int x) { //recebe 5
    x = x * 2;//5x2 =10
    printf("Dentro da função: %d\n", x);//10
}

int main() {
    int numero = 5;
    printf(" antes de chamar a funçao, o valor é = %d\n",numero);//5


    dobrar(numero);//dobrar(5)
    //dobrar


    printf("Fora da função: %d\n", numero );//valor original de numero continua 5
   


    return 0;
}