#include <iostream>
#include <cmath> 
using namespace std;
int main(){
int licznik = 0;
int suma = 0;
int max = -1298346132; 
int min = 127203947;
string pytanie;
int liczba;
do{
    cout<<"podaj liczbę: ";
    cin>>liczba;
    cout<<endl;
    suma = suma + liczba;
    if(liczba>max) max = liczba;
    if(min>liczba) min = liczba;
    licznik++;


cout<<"Czy koniec wprowadzania? T/N: ";
cin>>pytanie;
}while(pytanie != "T");

float srednia = suma/licznik;
cout<<"suma podanych liczb: "<<suma<<endl;
cout<<"srednia podanych liczb: "<<srednia<<endl;
cout<<"maksymalna z podanych liczb: "<<max<<endl;
cout<<"minimalna z podanych liczb: "<<min;


return 0;
}