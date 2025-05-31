#include <iostream>
using namespace std;

int main(){
int doacao = 0; // Inicializa a variável doaçao com 0
int escolha;
int escolha2;
do{
cout<<"## DOAÇAO ##\n";
cout<<"bem vindo ao sistema de doaçao\n";
cout<<"escolha uma doaçao:\n";

cout<<"(1)DOAR R$5,00\n         (2) DOAR R$10,00\n";
cout<<"(3) DOAR R$30,00\n         (4) DOAR R$50,00\n";
cout<<"(5) DOAR OUTERO VALOR\n";

cout<<"Digite a sua escolha: ";
cin>>escolha;

switch(escolha)
{
    case 1:
        cout<<"Obrigado por doar R$5,00!\n";
        break;
    case 2:
        cout<<"Obrigado por doar R$10,00!\n";
        break;
    case 3:
        cout<<"Obrigado por doar R$30,00!\n";
        break;
    case 4:
        cout<<"Obrigado por doar R$50,00!\n";
        break;
    case 5:
        cout<<"Digite o valor da doaçao: ";
        cin>>doacao;
        cout<<"Obrigado por doar R$"<<doacao<<"!\n";
        break;
    default:
        cout<<"Opção inválida!\n";
}
cout<<"digite 1 para doar novamente ou 0 para sair: ";
cin>>escolha2;

}while(escolha2==1);{
cout<<"Obrigado por usar o sistema de doaçao!\n";
cout<<"Total doado: R$"<<doacao<<"\n";}


return 0;
}