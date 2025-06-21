#include <iostream>
using namespace std;


int main(){
int senhadigitada;
int senha = 1234;
int tentativas = 0; 
  int opcao;


while(tentativas < 3) {
    cout << "Digite a senha: ";
    cin >> senhadigitada;

    if (senhadigitada == senha) {
        cout << "Acesso permitido!" << endl;
       break;
    } else {
        tentativas++;
        cout << "Senha incorreta. Tentativa " << tentativas << " de 3." << endl;
    }
    if(tentativas == 3) {
        cout << "Número máximo de tentativas atingido. Acesso negado." << endl;
    }
}
if(tentativas < 3) {
    
do{
  
    cout << "\n========= MENU =========\n";
cout << "1 - Ver saldo\n";
cout << "2 - Saque\n";
cout << "3 - Depósito\n";
cout << "4 - Sair\n";
cout << "========================\n";
cout << "Escolha uma opção: ";
    cin >> opcao;
    switch(opcao) {
        case 1:
            cout << "Seu saldo é: R$1000,00" << endl; 
            break;
        case 2:{
            cout << "Digite o valor do saque: ";
            int saque;
            cin >> saque;
            cout << "Saque de R$" << saque << " realizado com sucesso!" << endl; /
            break;}
        case 3:{
            cout << "Digite o valor do depósito: ";
            int deposito;
            cin >> deposito;
            cout << "Depósito de R$" << deposito << " realizado com sucesso!" << endl; 
            break;}
        case 4:
            cout << "Saindo do sistema. Obrigado por utilizar!" << endl;
            return 0; 
        default:
            cout << "Opção inválida. Tente novamente." << endl;
    }
}while(opcao != 4); 
}

return 0; 
}

   








