// Умова:
// Варіант 3: Обчислити суму трьох визначених інтегралів методом правих прямокутників:
// 1) f1(x) = x^3 + x на [0; 2]
// 2) f2(x) = exp(x) на [0; 1]
// 3) f3(x) = 1 / (x + 1) на [0; 2]
// Кількість розбиттів n = 1000 для кожного інтеграла.

#include <iostream>
#include <cmath>

using namespace std;

// Підінтегральні функції варіанта 3
double f1(double x) {
    return x * x * x + x;
}

double f2(double x) {
    return exp(x);
}

double f3(double x) {
    return 1.0 / (x + 1.0);
}

// Універсальна функція наближеного обчислення інтеграла методом правих прямокутників
double integrate(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;

    for (int i = 1; i <= n; ++i) {
        double x_i = a + i * h;
        sum += f(x_i);
    }

    return h * sum;
}

int main() {
    const int n = 1000;

    // Межі інтегрування для варіанта 3
    double a1 = 0.0, b1 = 2.0;
    double a2 = 0.0, b2 = 1.0;
    double a3 = 0.0, b3 = 2.0;

    // Обчислення кожного інтеграла через вказівник на відповідну функцію
    double I1 = integrate(f1, a1, b1, n);
    double I2 = integrate(f2, a2, b2, n);
    double I3 = integrate(f3, a3, b3, n);

    // Загальна сума інтегралів
    double S = I1 + I2 + I3;

    cout << "I1 = " << I1 << endl;
    cout << "I2 = " << I2 << endl;
    cout << "I3 = " << I3 << endl;
    cout << "S = I1 + I2 + I3 = " << S << endl;

    return 0;
}
