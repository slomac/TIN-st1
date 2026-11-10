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
void suma_tablicy(float tab[10]){
    float suma = 0;
    for(int i=0; i<10; i++){
        suma = suma + tab[i];
    }
    cout<<"Suma elementow tablicy wynosi: "<<suma<<endl;

}
void srednia_tablicy(float tab[10]){
    float suma = 0;
    for(int i = 0; i<10; i++){
        suma = suma + tab[i];
    }
    float srednia = suma/10;
    cout<<"Srednia elementow tablicy to: "<<srednia<<endl;
}
void minmax_tablicy(float tab[10]){
    float max = tab[0];
    float min = tab[0];
    for(int i = 0; i<10; i++){
        if(tab[i] < min) min = tab[i];
        else if(tab[i] > max) max = tab[i];
    }
    cout<<"Maksymalna wartosc w tablicy to: "<<max<<endl;
    cout<<"Minimalna wartosc w tablicy to: "<<min<<endl;
}
void zliczanie_elementow_tablicy(float tab[10]){
    int licznikujemnych = 0;
    int licznikdodatnich = 0; 
    int licznikzerowych = 0;
    for(int i = 0; i<10; i++){
        if(tab[i]<0) licznikujemnych++;
        else if(tab[i] == 0) licznikzerowych++;
        else if(tab[i] > 0) licznikdodatnich++;
    }
cout<<"Ujemnych elementow w tablicy jest: "<<licznikujemnych<<endl;
cout<<"Dodatnich elementow w tablicy jest: "<<licznikdodatnich<<endl;
cout<<"Zerowych  elementow w tablicy jest: "<<licznikzerowych<<endl;
}

int main(){
    float tab[10];
    wczytywanie_tablicy(tab);
    wypisz_tablice(tab);
    suma_tablicy(tab);
    srednia_tablicy(tab);
    minmax_tablicy(tab);
    zliczanie_elementow_tablicy(tab);
    return 0;
}