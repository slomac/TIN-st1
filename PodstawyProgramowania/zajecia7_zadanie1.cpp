#include <iostream> 
using namespace std; 
void wczytywanie_tablicy(float tab[10]){
    float tmp;
    for(int i = 0; i<10; i++){
    cout<<"Podaj "<<i+1<<" element tablicy: ";
    cin>>tmp;
    tab[i] = tmp;
    }
}
void wypisz_tablice(float tab[10]){
    for(int i = 0; i<10; i++){
        cout<<"tab["<<i<<"]"<<" = "<<tab[i]<<endl;
    }
}
int main(){
    float tab[10];
    wczytywanie_tablicy(tab);
    wypisz_tablice(tab);
    return 0;
}