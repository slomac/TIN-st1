#include <iostream>
using namespace std;
int main() {
int tab[10];
for(int i=0; i<10; i++){
    cout<<"Podaj liczbe: ";
    cin>>tab[i];
}
float suma = 0;
for(int i=0; i<10;i++){
    suma = suma + tab[i];
}
float srednia = suma/10;  
cout<<"suma liczb wynosi: "<<suma<<endl;
cout<<"srednia liczb wynosi: "<<srednia<<endl;  
return 0;
}