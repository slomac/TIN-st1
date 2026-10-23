#include<iostream>
#include <string>
#include <cmath>
using namespace std;

inline int sprawdz(char znak)
{
	//jesli jest mala litera
	if(znak >= 'a' && znak <= 'z') return 0;
	//jesli jest duza litera
	if(znak >= 'A' && znak <= 'Z') return 1;
	//inna ni� litera
	return 2;}
void szyfruj(string &tab)
{		
	//sprawdzenie, czy klucz miesci sie w zakresie
	int klucz = 13;
	
	int pom;
	char a, z;
	
	for(int i = 0; i < tab.size(); i++)
	{
		pom = sprawdz(tab[i]);
		//ustalienie wielkosci litery
		if(pom < 2)
		{
			if(pom == 0) 
				a = 'a', z = 'z';
			else
				a = 'A', z = 'Z';
	
			if(klucz >= 0)
					
				if(tab[i] + klucz <= z)
					tab[i] += klucz;
				else
					tab[i] = tab[i] + klucz - 26; 
			else
				if(tab[i] + klucz >= a)
					tab[i] += klucz;
				else
					tab[i] = tab[i] + klucz + 26;
		}
	}
}
int main(){
	
	string tab;
	for(int i = 0; i>-1; i++){
		cin>>tab;
		if(tab != "!"){
			szyfruj(tab);
			cout<<tab;
			cout<<endl;
		}
		else break;
			
	}
	return 0;
}