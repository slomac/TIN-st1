#include <iostream>
using namespace std;
int main(){
char k;
int licznikduzych = 0;
int licznik = 0;
do {
    cin>>k;
    licznik ++;
if(k<=90 and k>=65) licznikduzych++;



}while(k != 'K' and k != 'k');
cout<<"liczba znakow przed 'k': "<<licznik - 1<<endl;
cout<<"liczba duzych znakow przed 'K': "<<licznikduzych;
return 0;
}