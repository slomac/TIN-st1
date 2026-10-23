#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int iterations = 5; // Każda iteracja podwaja liczbę poprawnych cyfr
    
    double a = 1.0;
    double b = 1.0 / std::sqrt(2.0);
    double t = 1.0 / 4.0;
    double p = 1.0;

    for (int i = 0; i < iterations; ++i) {
        double a_next = (a + b) / 2.0;
        double b_next = std::sqrt(a * b);
        double t_next = t - p * std::pow(a - a_next, 2);
        double p_next = 2.0 * p;

        a = a_next;
        b = b_next;
        t = t_next;
        p = p_next;
    }

    double pi_approx = std::pow(a + b, 2) / (4.0 * t);

    std::cout << std::fixed << std::setprecision(15);
    std::cout << "Przyblizenie liczby pi: " << pi_approx << '\n';

    return 0;
}
