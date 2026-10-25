// Умова:
// Трикутник задається координатами своїх вершин на площині:
// A(x1, y1), B(x2, y2), C(x3, y3). Визначити, чи є цей трикутник гострокутним.

#include <iostream>

int main() {
    double *x1 = new double, *y1 = new double;
    double *x2 = new double, *y2 = new double;
    double *x3 = new double, *y3 = new double;

    std::cin >> *x1 >> *y1 >> *x2 >> *y2 >> *x3 >> *y3;

    double *cross = new double((*x2 - *x1) * (*y3 - *y1) - (*y2 - *y1) * (*x3 - *x1));
    if (*cross == 0.0) {
        std::cout << "NO" << std::endl;
        delete cross;
        delete x1; delete y1;
        delete x2; delete y2;
        delete x3; delete y3;
        return 0;
    }

    double *a2 = new double((*x2 - *x3) * (*x2 - *x3) + (*y2 - *y3) * (*y2 - *y3));
    double *b2 = new double((*x1 - *x3) * (*x1 - *x3) + (*y1 - *y3) * (*y1 - *y3));
    double *c2 = new double((*x1 - *x2) * (*x1 - *x2) + (*y1 - *y2) * (*y1 - *y2));

    if (*a2 + *b2 > *c2 && *a2 + *c2 > *b2 && *b2 + *c2 > *a2) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    delete c2;
    delete b2;
    delete a2;
    delete cross;
    delete x1; delete y1;
    delete x2; delete y2;
    delete x3; delete y3;

    return 0;
}
