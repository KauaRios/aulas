#include <stdio.h>
void saudacao()
{
    printf("ola,mundo\n");
}
int main()
{
    void (*ptr)() = saudacao;

    ptr();

    return 0;
}