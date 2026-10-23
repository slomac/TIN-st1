#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
int kosc1 = 0;
int kosc2 = 0;
for(int i = 0; i<10; i++){
cout<<"rzut numer: "<<i+1<<endl;   
kosc1 = rand()%7;
kosc2 = rand()%7;
cout<<"Wylosowana liczba na pierwszej kosci to "<<kosc1<<endl;
cout<<"Wylosowana liczba na drugiej kosci to "<<kosc2<<endl;}
return 0;
}