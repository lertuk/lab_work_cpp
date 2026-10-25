#include <iostream>
#include <cmath>

int main() {
    double x, eps;
    std::cin >> x >> eps;

    double sum = 0.0;
    double term = 1.0;
    int n = 0;

    while (std::abs(term) >= eps) {
        sum += term;
        ++n;
        term = -term * x / n;
    }

    std::cout << sum << std::endl;

    return 0;
}
