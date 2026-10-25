#include <iostream>

int main() {
    double x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double cross_product = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if (cross_product == 0.0) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    double a2 = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
    double b2 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
    double c2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

    if (a2 + b2 > c2 && a2 + c2 > b2 && b2 + c2 > a2) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
