#include <iostream>
using namespace std;


int main (){

double soma=0;

for(int i=1; i<=4; i++){
    cout<<"digite a "<<i<<" nota: ";
    double nota;
    cin>>nota;
    soma+=nota;
}
double  media=soma/4;
cout<<"total: "<<soma<<endl;    
cout<<"media: "<<media<<endl;



if (media >= 7.0) {
    cout << "Aprovado" << endl;
} else if (media >= 5.0) {
    cout << "Recuperacao" << endl;
} else {
    cout << "Reprovado" << endl;
}

return 0;
}