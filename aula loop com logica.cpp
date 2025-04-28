#include <iostream>
using namespace std;

int main(){


    int n =0;
    cout<<"digite o valor da tabuada que deseja "<<endl;
    cin>>n;


for(int i=1;i<=10;i++){
cout<<n<<" x"<<i<<"="<<n*i<<endl;
if(n*i==0){
    cout<<"o valor digitado foi 0<<endl;"<<endl;
}else if(n*i>0){
    cout<<"o valor digitado foi positivo"<<endl;
}else if(n*i<0){
    cout<<"o valor digitado foi negativo"<<endl;

}

    




}


return 0;


}