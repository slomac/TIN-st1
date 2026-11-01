#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
using namespace std;
void autor(){

    cout<<"Maciej Slominski, numer albumu 296250";
}
int dodaj(int a, int b){
return a+b;
}
double polekola(int r){ 
    return M_PI*r*r;
}
void sortujRosnaco(int &a, int &b) {
    if (a > b) {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
}

int main(){
  
    autor();
    cout<<endl;
    int a,b;
    cout<<"Podaj dwie liczby calkowite: ";
    cin>>a>>b;
    cout<<"Dodawanie: "<<dodaj(a,b)<<endl;
    cout<<"Podaj promien kola, ktorego pole mam obliczyc: ";
    int r;
    cin>>r;
    cout<<"Pole kola: "<<polekola(r)<<endl;
    cout<<"Podaj dwie liczby, ktore mam posortowac: ";
    int c,d;
    cin>>c>>d;
    sortujRosnaco(c,d);
    cout<<"Wieksza: "<<d<<" Mniejsza: "<<c<<endl;
    
    return 0;
}