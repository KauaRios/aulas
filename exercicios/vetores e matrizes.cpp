#include <iostream>
using namespace std;

int main(){

    int array[5] = {};
    int maior;
    int pos;
    cout << "Digite 5 numeros: " << endl;
    for(int i = 0; i < 5; i++){
        cin >> array[i];
    }
    maior = array[0];
    pos = 0;
    for(int i = 1; i < 5; i++){
        if(array[i] > maior){
            maior = array[i];
            pos = i;
        }
    } 

    cout << "O maior numero  digitado é : " << maior << endl;
    cout << "Sua posicao eh: " << pos << endl;



return 0;
}

