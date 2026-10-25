// Умова:
// Дано дійсне число a. З'ясувати, чи належить це число інтервалу
// (3;7) U [8;9) U (11;22.4).

#include <iostream>

int main() {
    double *a = new double;
    std::cin >> *a;

    bool *in_interval = new bool(
        (*a > 3.0 && *a < 7.0) ||
        (*a >= 8.0 && *a < 9.0) ||
        (*a > 11.0 && *a < 22.4)
    );

    if (*in_interval) {
        std::cout << "Число належить інтервалу" << std::endl;
    } else {
        std::cout << "Число НЕ належить інтервалу" << std::endl;
    }

    delete in_interval;
    delete a;

    return 0;
}
