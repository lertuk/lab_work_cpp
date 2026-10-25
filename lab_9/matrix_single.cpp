// Умова:
// Варіант 3. Об'єкт «Матриця»
// Поля: кількість рядків і стовпців; елементи у std::vector<double> або прямокутному вкладеному контейнері.
// Методи: введення; виведення за рядками; пошук найбільшого та найменшого елементів.
// Розміри мають бути додатними. Перевірити роботу методів, копіювання, незалежність копії та граничні випадки.

#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>
#include <utility>

class Matrix {
public:
    std::size_t rows{1};
    std::size_t cols{1};
    std::vector<double> data{0.0}; // Зберігання елементів послідовно (розмір = rows * cols)

    // Конструктор за замовчуванням (матриця 1x1 з нулем)
    Matrix() = default;

    // Конструктор із параметрами розмірів
    Matrix(std::size_t r, std::size_t c)
        : rows{r == 0 ? 1 : r}, cols{c == 0 ? 1 : c}, data((r == 0 ? 1 : r) * (c == 0 ? 1 : c), 0.0) {}

    // Конструктор із параметрами розмірів та готовими даними
    Matrix(std::size_t r, std::size_t c, const std::vector<double>& initial_data)
        : rows{r == 0 ? 1 : r}, cols{c == 0 ? 1 : c} {
        std::size_t total = rows * cols;
        if (initial_data.size() == total) {
            data = initial_data;
        } else {
            data.assign(total, 0.0);
        }
    }

    // Введення елементів матриці з консолі
    void input() {
        std::cout << "Введіть " << (rows * cols) << " елементів для матриці (" 
                  << rows << "x" << cols << "):\n";
        for (std::size_t i = 0; i < rows * cols; ++i) {
            std::cin >> data[i];
        }
    }

    // Виведення матриці по рядках (константний метод)
    void print() const {
        for (std::size_t i = 0; i < rows; ++i) {
            for (std::size_t j = 0; j < cols; ++j) {
                std::cout << data[i * cols + j] << "\t";
            }
            std::cout << '\n';
        }
    }

    // Пошук найбільшого елемента (повертає std::nullopt, якщо матриця порожня)
    std::optional<double> findMax() const {
        if (data.empty()) {
            return std::nullopt;
        }
        return *std::max_element(data.begin(), data.end());
    }

    // Пошук найменшого елемента (повертає std::nullopt, якщо матриця порожня)
    std::optional<double> findMin() const {
        if (data.empty()) {
            return std::nullopt;
        }
        return *std::min_element(data.begin(), data.end());
    }
};

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
    Matrix m1_copy = m1; // Створення копії
    m1_copy.data[0] = 999.9; // Змінюємо перший елемент лише в копії

    std::cout << "Змінена матриця m1_copy (перший елемент 999.9):\n";
    m1_copy.print();
    std::cout << "Оригінальна матриця m1 (стан не змінився):\n";
    m1.print();

    std::cout << "\n=== 3. Граничні випадки ===\n";
    std::cout << "а) Граничний випадок: Матриця 1x1 (один елемент):\n";
    Matrix m_single(1, 1, {42.0});
    m_single.print();
    std::cout << "Max: " << *m_single.findMax() << ", Min: " << *m_single.findMin() << '\n';

    std::cout << "\nб) Граничний випадок: Спроба задати некоректні розміри (0x0):\n";
    Matrix m_zero(0, 0); // Конструктор автоматично захистить розмір, задавши 1x1
    std::cout << "Створено безпечну матрицю розміром " << m_zero.rows << "x" << m_zero.cols << ":\n";
    m_zero.print();

    return 0;
}
