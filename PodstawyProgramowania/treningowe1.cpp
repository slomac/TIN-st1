#include <iostream> 
using namespace std;
int main() {
    
    float a,b;
    cout << "Podaj liczbe a: ";
    cin>>a;
    cout<< "Podaj liczbe b: ";
    cin>>b;
    float suma = 0;
    float min;
    float max;
    if(a<b) {min = a; max = b;}
    else {min = b; max = a;}
    for(int i =min; i<=max; i++){suma = suma + i;}
float srednia = suma/(max-min+1);


cout<<"suma liczb od "<<min<<" do "<<max<<" wynosi: "<<suma<<endl;
cout<<"srednia liczb od "<<min<<" do "<<max<<" wynosi: "<<srednia<<endl;

}