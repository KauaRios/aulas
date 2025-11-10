#include <stdio.h>
#include <stdlib.h>



// criaçao de funçao 
void display(int var,int *ptr){
    printf("\n\n");
printf("conteudo de var =%d\n",var);
printf("endereço de var = %p\n",var);
printf("conteudo apontado por ptr = %d\n",*ptr);
printf("endereço apontado por ptr = %p\n",ptr);
printf("endereco do ptr=%p\n",&ptr);



}


int main(){


int var=15;
int *ptr;


ptr=&var;





display(var,ptr);

*ptr=73;//ponteiro atualizando o conteudo de var 


printf("\n\n");
printf("conteudo de var =%d\n",var);
printf("endereço de var = %p\n",var);
printf("conteudo apontado por ptr = %d\n",*ptr);
printf("endereço apontado por ptr = %p\n",ptr);
printf("endereco do ptr=%p\n",&ptr);


printf("\n\nend");
while(1);
return 0;


}// end main







//ponteiros:
//*ptr: o apontado por, conteudo do endereço da variavel que ptr aponta
//ptr: endereço da variavel
//&ptr: verei o endereço do ponteiro 
