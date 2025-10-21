#include <stdio.h>

int main(){
    int a,b;
    int*ponteiro=&a;
    a=10;
    b=a+20;
    *ponteiro=b*2;

    printf("%d",a);
    return 0;
}