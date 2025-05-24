
#include <iostream>
using namespace std;
int main() {
   float peso,altura;

   cout<<"qual seu peso em kg? ";
   cin>>peso;

   cout<<"qual sua altura em metros? ";
   cin>>altura;

    float imc = peso / (altura * altura);


    cout<<"seu imc e: "<<imc<<endl;

    if (imc < 18.5) {
        cout << "Abaixo do peso" << endl;
    } else if (imc >= 18.5 && imc < 24.9) {
        cout << "Peso normal" << endl;
    } else if (imc >= 25 && imc < 29.9) {
        cout << "Sobrepeso" << endl;
    } else {
        cout << "Obesidade" << endl;
    }
    

    
    
    
   

    return 0;
}
