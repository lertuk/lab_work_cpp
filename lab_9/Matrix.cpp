#include "Matrix.h"
#include <iostream>
#include <algorithm>

Matrix::Matrix(std::size_t r, std::size_t c)
    : rows{r == 0 ? 1 : r}, cols{c == 0 ? 1 : c}, data((r == 0 ? 1 : r) * (c == 0 ? 1 : c), 0.0) {}

Matrix::Matrix(std::size_t r, std::size_t c, const std::vector<double>& initial_data)
    : rows{r == 0 ? 1 : r}, cols{c == 0 ? 1 : c} {
    std::size_t total = rows * cols;
    if (initial_data.size() == total) {
        data = initial_data;
    } else {
        data.assign(total, 0.0);
    }
}

void Matrix::input() {
    std::cout << "Введіть " << (rows * cols) << " елементів для матриці (" 
              << rows << "x" << cols << "):\n";
    for (std::size_t i = 0; i < rows * cols; ++i) {
        std::cin >> data[i];
    }
}

void Matrix::print() const {
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            std::cout << data[i * cols + j] << "\t";
        }
        std::cout << '\n';
    }
}

std::optional<double> Matrix::findMax() const {
    if (data.empty()) {
        return std::nullopt;
    }
    return *std::max_element(data.begin(), data.end());
}

std::optional<double> Matrix::findMin() const {
    if (data.empty()) {
        return std::nullopt;
    }
    return *std::min_element(data.begin(), data.end());
}
