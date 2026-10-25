#include <iostream>
#include "Matrix.h"

int main() {
    std::cout << "=== 1. Звичайний випадок: Створення матриці 2x3 ===\n";
    Matrix m1(2, 3, {3.5, -2.1, 8.0, 0.0, 14.4, -9.2});
    std::cout << "Матриця m1:\n";
    m1.print();

    if (auto max_val = m1.findMax()) {
        std::cout << "Найбільший елемент m1: " << *max_val << '\n';
    }
    if (auto min_val = m1.findMin()) {
        std::cout << "Найменший елемент m1: " << *min_val << '\n';
    }

    std::cout << "\n=== 2. Перевірка копіювання та незалежності копії ===\n";
    Matrix m1_copy = m1;
    m1_copy.data[0] = 999.9;

    std::cout << "Змінена матриця m1_copy (перший елемент 999.9):\n";
    m1_copy.print();
    std::cout << "Оригінальна матриця m1 (стан не змінився):\n";
    m1.print();

    std::cout << "\n=== 3. Граничні випадки ===\n";
    std::cout << "а) Граничний випадок: Матриця 1x1:\n";
    Matrix m_single(1, 1, {42.0});
    m_single.print();
    std::cout << "Max: " << *m_single.findMax() << ", Min: " << *m_single.findMin() << '\n';

    std::cout << "\nб) Граничний випадок: Спроба задати розміри 0x0:\n";
    Matrix m_zero(0, 0);
    std::cout << "Створено безпечну матрицю розміром " << m_zero.rows << "x" << m_zero.cols << ":\n";
    m_zero.print();

    return 0;
}
