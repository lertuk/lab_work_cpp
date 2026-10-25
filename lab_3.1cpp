#include <iostream>

int main() {
    double a;
    int n;
    std::cin >> a >> n;

    if (n <= 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    double sum = 0.0;
    double term = 1.0 / (a * a);
    double p = a;

    sum += term;

    for (int k = 2; k <= n; ++k) {
        p *= (a + k - 1);
        term = term * k / p;
        sum += term;
    }

    std::cout << sum << std::endl;

    return 0;
}
