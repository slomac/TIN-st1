#include <iostream>
#include <cmath>
using namespace std;
void liczby(int a, int b){
int suma = a+b;
int roznica; 
if(a>b)  roznica = a - b;
else roznica = b - a;
int iloczyn = a*b;
int iloczyna = a/b;
int iloczynb = b/a;
int potegaa = pow(a,b);
int potegab = pow(b,a);
int pierwiasteka = sqrt(a);
int pierwiastekb = sqrt(b);
float  eksponenta = exp(a);
float  eksponentb = exp(b);

cout<<"Suma: "<<suma<<endl;
cout<<"Roznica: "<<roznica<<endl;
cout<<"Iloczyn: "<<iloczyn<<endl;     
cout<< "Iloraz a/b: "<<iloczyna<<endl;
cout<< "Iloraz b/a: "<<iloczynb<<endl;
cout<<"Potega a^b: "<<potegaa<<endl;
cout<<"Potega b^a: "<<potegab<<endl;
cout<<"Pierwiastek a: "<<pierwiasteka<<endl;
cout<<"Pierwiastek b: "<<pierwiastekb<<endl;
cout<<"Eksponent a: "<<eksponenta<<endl;
cout<<"Eksponent b: "<<eksponentb<<endl;
}
void kreskaminus(int n){
    for(int i = 0; i<n; i++) cout<<"-";
}
