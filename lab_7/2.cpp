// Умова:
// Використовуючи підпрограму наближеного знаходження визначеного інтегралу
// за формулою правих прямокутників, обчислити значення виразу:
// s = \int_{a}^{3} \sqrt{4x + \sin\sqrt{x^3}} dx + \int_{a}^{b} \sqrt{4x + \sin\sqrt{x^3}} dx

#include <iostream>
#include <cmath>

using namespace std;

// Підінтегральна функція: g(x) = sqrt(4x + sin(sqrt(x^3)))
double g(double x) {
    return sqrt(4.0 * x + sin(sqrt(x * x * x)));
}

// Наближене обчислення визначеного інтеграла методом правих прямокутників
double right_rectangles_integral(double left, double right, int n = 1000) {
    if (left == right) {
        return 0.0;
    }
    
    double sign = 1.0;
    if (left > right) {
        swap(left, right);
        sign = -1.0;
    }

    double h = (right - left) / n;
    double sum = 0.0;

    for (int i = 1; i <= n; ++i) {
        double x_i = left + i * h;
        sum += g(x_i);
    }

    return sign * sum * h;
}

int main() {
    double a, b;
    cout << "Введіть межі інтегрування a та b (a >= 0, b >= 0): ";
    cin >> a >> b;

    if (a < 0.0 || b < 0.0) {
        cout << "Значення a та b мають бути невід'ємними через область визначення функції!" << endl;
        return 1;
    }

    double int1 = right_rectangles_integral(a, 3.0);
    double int2 = right_rectangles_integral(a, b);
    double s = int1 + int2;

    cout << "Інтеграл від " << a << " до 3: " << int1 << endl;
    cout << "Інтеграл від " << a << " до " << b << ": " << int2 << endl;
    cout << "s = " << s << endl;

    return 0;
}
