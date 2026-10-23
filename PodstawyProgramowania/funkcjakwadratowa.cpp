#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;

    cout << "Podaj wspolczynniki a, b, c funkcji kwadratowej: ";
    cin >> a >> b >> c;

    if (a == 0) {
        cout << "To nie jest funkcja kwadratowa, bo wspolczynnik a = 0." << endl;
        return 0;
    }

    double delta = b * b - 4 * a * c;

    cout << "Delta = " << delta << endl;

    if (delta > 0) {
        double x1 = (-b - sqrt(delta)) / (2 * a);
        double x2 = (-b + sqrt(delta)) / (2 * a);
        cout << "Funkcja ma dwa miejsca zerowe: " << x1 << " oraz " << x2 << endl;
    } else if (delta == 0) {
        double x = -b / (2 * a);
        cout << "Funkcja ma jedno miejsce zerowe: " << x << endl;
    } else {
        cout << "Funkcja nie ma miejsc zerowych w zbiorze liczb rzeczywistych." << endl;
    }

    return 0;
}
