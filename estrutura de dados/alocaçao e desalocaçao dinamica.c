#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *a, b;
    b = 10;
    a = (int *)malloc(sizeof(int));
    *a = 20;
    free(a);
    a = &b;

    printf("valor de a é : %d\n", *a);

    return 0;
}
