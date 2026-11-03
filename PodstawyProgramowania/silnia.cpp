#include <iostream>
#include <cmath>
using namespace std;

unsigned long long silniaIteracyjnie(unsigned int n) {
    unsigned long long wynik = 1;
    for (unsigned int i = 2; i <= n; ++i) {
        wynik *= i;
    }
    return wynik;
}
unsigned long long silnia_rek( unsigned long long n) {
    if (n <= 1) { 
        return 1;
    }
    return n * silnia_rek(n - 1);
}
int main(){
    unsigned int a;
    cin>>a;
    cout<<"Iteracyjnie: "<<silniaIteracyjnie(a)<<endl;
    cout<<"Rekurencyjnie: "<<silnia_rek(a)<<endl;





return 0;
}