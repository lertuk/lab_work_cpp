#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <optional>
#include <cstddef>

class Matrix {
public:
    std::size_t rows{1};
    std::size_t cols{1};
    std::vector<double> data{0.0};

    Matrix() = default;
    Matrix(std::size_t r, std::size_t c);
    Matrix(std::size_t r, std::size_t c, const std::vector<double>& initial_data);

    void input();
    void print() const;
    std::optional<double> findMax() const;
    std::optional<double> findMin() const;
};

#endif // MATRIX_H
