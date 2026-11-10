#include <iostream> 
using namespace std;
void tablica(int tab[5]){
    int temp;
    for(int i = 0; i<5; i++){
    cout<<"Podaj "<<i+1<<" element tablicy: ";
    cin>>temp;
    tab[i] = temp;
    }
}

int main(){
    int tabA[5];
    int tabB[5];
    cout<<"Tablica A: "<<endl;
    tablica(tabA);
    cout<<"Tablica B: "<<endl;
    tablica(tabB);
    cout<<"Tablica A: "<<endl;
    for(int i = 0; i<5; i++){
        cout<<tabA[i]<<" ";
     }
     cout<<endl;
     cout<<"Tablica B: "<<endl;
     for(int i = 0; i<5; i++){
        cout<<tabB[i]<<" ";
     }
     cout<<endl;
     int tabC[5];

     for(int i = 0; i<5; i++){
        tabC[i] = tabA[i] + tabB[i];
     }
     cout<<"Tablica C (Suma tablic A i B): "<<endl;
    for(int i = 0; i<5; i++){
        cout<<tabC[i]<<" ";}

return 0;
}