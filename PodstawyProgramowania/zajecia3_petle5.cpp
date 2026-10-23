#include <iostream>

using namespace std;

int main() {
    int wysokosc;
    cout << "Podaj wysokosc choinki: ";
    cin >> wysokosc;

    if (wysokosc <= 0) {
        cout << "Wysokosc musi byc wieksza od zera!" << endl;
        return 0;
    }

    // Pętla sterująca kolejnymi wierszami (od 1 do wysokości)
    for (int i = 1; i <= wysokosc; ++i) {
        
        // 1. Wypisanie spacji wiodących (dla wyśrodkowania choinki)
        for (int j = 0; j < wysokosc - i; ++j) {
            cout << " ";
        }
        
        // 2. Wypisanie gwiazdek (liczba gwiazdek rośnie nieparzyście: 1, 3, 5, 7...)
        for (int k = 0; k < (2 * i - 1); ++k) {
            cout << "*";
        }
        
        // Przejście do nowego wiersza
        cout << endl;
    }

    return 0;
}