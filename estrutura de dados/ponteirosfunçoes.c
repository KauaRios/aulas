#include <stdio.h>
void saudacao()
{
    printf("ola,mundo\n");
}
int main()
{
    void (*ptr)() = saudacao;

    ptr();

    ptr

    return 0;
}