#include <iostream>
#include <array> 
using namespace std; 
void WCZYTAJ_TAB(int tab[], int n){
    float tmp;
    for(int i = 0; i<n; i++){
    cout<<"Podaj "<<i+1<<" element tablicy: ";
    cin>>tmp;
    tab[i] = tmp;
    }
}
void WYPISZ_TAB(int tab[], int n){
    for(int i = 0; i<n; i++){
        cout<<"tab["<<i<<"]"<<" = "<<tab[i]<<endl;
    }
}
void SUMA_TAB(int tab[], int tab2[], int tab3[], int n){
   string zapytanie;
    cout<<"Czy chcesz odjac, czy dodac do siebie dwie tablice? (odjac/dodac): ";
    cin>>zapytanie;
    if(zapytanie == "dodac"){   
        for(int i = 0; i<n; i++){
        tab3[i] = tab[i] + tab2[i];
        }
    }
    else if(zapytanie == "odjac"){  
        for(int i = 0; i<n; i++){
        tab3[i] = tab[i] - tab2[i];
            }
        }
    }
int main(){
    int n;
    cout<<"podaj wielkosc tablic na ktorych mam pracowac: ";
    cin>>n;
    cout<<endl;
    int tablica1[n];
    int tablica2[n];
    cout<<"Podaj elementy tablicy A: "<<endl;
    WCZYTAJ_TAB(tablica1, n);
    cout<<"Podaj elementy tablicy B: "<<endl;
    WCZYTAJ_TAB(tablica2, n);
    int tablica3[n];
    SUMA_TAB(tablica1, tablica2, tablica3, n);
    cout<<"tablica A: "<<endl;
    WYPISZ_TAB(tablica1, n);
    cout<<"tablica B: "<<endl; 
    WYPISZ_TAB(tablica2, n);
    cout<<"tablica C: "<<endl;
    WYPISZ_TAB(tablica3, n);
    return 0;
}