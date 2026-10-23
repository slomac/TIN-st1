#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Podaj liczbe n: ";
    cin>>n;
    int silnia =1;
    for(int i = 1; i<=n; i++){
        silnia = silnia * i;
    }
    cout<<"silnia z liczby "<<n<<" wynosi: "<<silnia<<endl; 
    return 0;
}