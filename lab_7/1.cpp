// Умова:
// За даними дійсними числами a і b обчислити u = f(a) + f(2) + f(b), де
// f(x) = \sum_{i=1}^{5} x^i, якщо x > 0;
// f(x) = \prod_{i=1}^{5} x^i, інакше.

#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    if (x > 0.0) {
        double sum = 0.0;
        double current_power = x;
        for (int i = 1; i <= 5; ++i) {
            sum += current_power;
            current_power *= x;
        }
        return sum;
    } else {
        // \prod_{i=1}^{5} x^i = x^(1 + 2 + 3 + 4 + 5) = x^15
        double prod = 1.0;
        double current_power = x;
        for (int i = 1; i <= 5; ++i) {
            prod *= current_power;
            current_power *= x;
        }
        return prod;
    }
}

int main() {
    double a, b;
    cout << "Введіть дійсні числа a та b: ";
    cin >> a >> b;

    double u = f(a) + f(2.0) + f(b);

    cout << "u = " << u << endl;

    return 0;
}
