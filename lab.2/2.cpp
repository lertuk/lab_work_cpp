#include <iostream>
#include <cmath>

int main() {
    double x;
    std::cin >> x;

    if (x <= 0) {
        return 1;
    }

    double expr = x * x + std::log(x);
    double y;

    if (expr > 0) {
        y = std::cos(expr);
    } else if (expr < 0) {
        y = 1.0 / expr;
    } else {
        y = std::cos(x);
    }

    std::cout << y << std::endl;

    return 0;
}
