#include <iostream>
using namespace std;
int main(){
float wzrost; 
cout<<"Podaj swoj wzrost w centymetrach: ";
cin>>wzrost;
if(wzrost<150) cout<<"Jestes niski"<<endl;
else if(wzrost>=150 && wzrost<180) cout<<"Jestes sredniego wzrostu"<<endl;
else cout<<"Jestes wysoki"<<endl;

return 0;
}