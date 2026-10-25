// Умова:
// Обчислити значення функції y залежно від x:
// y = cos(x^2 + ln(x)), якщо x^2 + ln(x) > 0;
// y = 1 / (x^2 + ln(x)), якщо x^2 + ln(x) < 0;
// y = cos(x), якщо x^2 + ln(x) == 0.

#include <iostream>
#include <cmath>

int main() {
    double *x = new double;
    std::cin >> *x;

    if (*x <= 0.0) {
        delete x;
        return 1;
    }

    double *expr = new double(*x * *x + std::log(*x));
    double *y = new double;

    if (*expr > 0.0) {
        *y = std::cos(*expr);
    } else if (*expr < 0.0) {
        *y = 1.0 / *expr;
    } else {
        *y = std::cos(*x);
    }

    std::cout << *y << std::endl;

    delete y;
    delete expr;
    delete x;

    return 0;
}
