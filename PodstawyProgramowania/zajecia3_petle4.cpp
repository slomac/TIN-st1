#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Podaj liczbe n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Liczba n musi byc wieksza od zera!" << endl;
        return 0;
    }

    double suma = 0.0;

    // Pętla sumująca kolejne wyrazu szeregu
    for (int i = 1; i <= n; ++i) {
        suma += 1.0 / i; // 1.0 wymusza dzielenie zmiennoprzecinkowe
    }

    cout << "Suma szeregu dla n = " << n << " wynosi: " << suma << endl;

    return 0;
}