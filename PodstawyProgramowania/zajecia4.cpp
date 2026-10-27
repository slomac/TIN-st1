#include <iostream>

using namespace std;

// 1. Przekazanie przez wartość
void Posortuj_1(int a, int b) {
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    // Zmiany widoczne są tylko tutaj i giną po zakończeniu funkcji.
}

// 2. Przekazanie przez wskaźnik/adres
void Posortuj_2(int *a, int *b) {
    if (*a > *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

// 3. Przekazanie przez referencję/alias
void Posortuj_3(int &a, int &b) {
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
}

int main() {

    int x,y;
    cout<<"podaj dwie liczby:";
    cin>>x>>y;

    // Test Posortuj_1 (przez wartość)
    int x1 = x, y1 = y;
    cout << "Przed Posortuj_1: x = " << x1 << ", y = " << y1 << endl;
    Posortuj_1(x1, y1);
    cout << "Po Posortuj_1 (brak zmian): x = " << x1 << ", y = " << y1 << "\n\n";

    // Test Posortuj_2 (przez wskaźnik)
    int x2 = x, y2 = y;
    cout << "Przed Posortuj_2: x = " << x2 << ", y = " << y2 << endl;
    Posortuj_2(&x2, &y2); // Przekazujemy adresy za pomocą operatora &
    cout << "Po Posortuj_2 (posortowane): x = " << x2 << ", y = " << y2 << "\n\n";

    // Test Posortuj_3 (przez referencję)
    int x3 = x, y3 = y;
    cout << "Przed Posortuj_3: x = " << x3 << ", y = " << y3 << endl;
    Posortuj_3(x3, y3); // Wywołujemy normalnie, C++ sam dba o referencje
    cout << "Po Posortuj_3 (posortowane): x = " << x3 << ", y = " << y3 << endl;

    return 0;
}