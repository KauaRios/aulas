#include <stdio.h>
int main()
{
    int x = 10;  //
    int *p = &x; // ponteiro 'p'recebe o endereco de 'x'

    printf("valor de x: %d\n", x);
    printf("endereco de x: %p\n", &x);
    printf("conteudo de p (o endereco): %p\n", p);
    printf("o valor apontado por p: %d\n", *p);

    *p = 20; // troco o valor do ponteiro por '20' logo x=20

    printf("novo valor de x : %d\n", x);

    return 0;
}
