#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
int randomowa = 0;
for(int i = 0; i<10; i++){
randomowa = rand()%101;
cout<<"Wylosowana liczba to "<<randomowa<<endl;
}
return 0;
}