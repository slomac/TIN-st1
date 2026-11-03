#include <iostream>
#include <cmath>
#include <iomanip>

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
int potega(int a, int b){
    for(int i = 1; i<=b; i++){
        a = a*b;
    }
return a;
}
long long fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
     long long a = 0;
     long long b = 1;
     long long c = 0;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
bool pierwsza(int a){
    int licznik = 0;
    if(a<2) return false;
    for(int i = 2; i<a*a; i++){
        if(a%i ==0) licznik++;
    }
    if(licznik > 0 ) return false;
    return true;
}


double Euler(int x=15) {
    double e = 1.0;      
    double wyraz = 1.0;  

    for (int i = 1; i < x; ++i) {
        wyraz /= i;      
        e += wyraz;     
    }

    return e;
}
int nwd(int a, int b) {
    while (b != 0) {
        int pom = b;
        b = a % b; 
        a = pom;
    }
    return a;
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
    cout<<"podaj wykladnik oraz potege: "<<endl;
    int e,f;
    cin>>e>>f;
    cout<<potega(e,f)<<endl;
    cout<<"Podaj, ktory element ciagu fibbonaciego chcesz abym policzyl: "<<endl;
    int g;
    cin>>g;
    cout<<g<<" Liczba fibonacciego to: "<<fibonacci(g);
    cout<<"Podaj liczbe, a ja sprawdze czy jest pierwsza: "<<endl;
    int h;
    cin>>h;
    if(pierwsza(h) == 1) cout<<"Pierwsza"<<endl;
    else cout<<"Nie jest pierwsza"<<endl;

    cout<<"Liczba eulera z dokladnoscia 15 iteracji: "<<Euler()<<endl;

    cout<<"Podaj dwie liczby, ktorych NWD chcesz obliczyc: "<<endl;
    int i, j;
    cout<<"NWD tych liczb to: "<<nwd(i,j)<<endl;
    return 0;
}