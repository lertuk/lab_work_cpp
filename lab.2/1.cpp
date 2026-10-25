#include <iostream>

int main() {

    std::setlocale(LC_ALL, "Ukrainian");

    double a;
    std::cout << "Введіть дійсне число a: ";
    std::cin >> a;
    if ((a > 3 && a < 7) || (a >= 8 && a < 9) || (a > 11 && a < 22.4)) {
        std::cout << "Число " << a << " належить заданому інтервалу." << std::endl;
    } else {
        std::cout << "Число " << a << " НЕ належить заданому інтервалу." << std::endl;
    }

    return 0;
}
