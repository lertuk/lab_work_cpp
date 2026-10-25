// Умова:
// Дано двовимірний масив дійсних чисел A[n][m]. Написати програму,
// що переформовує масив A[n][m] таким чином, щоб його стовбці
// розташувались в порядку зростання їх поелементних сум.

#include <iostream>
#include <utility>

int main() {
    int n, m;
    std::cin >> n >> m;

    if (n <= 0 || m <= 0) {
        return 0;
    }

    double A[100][100];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> A[i][j];
        }
    }

    double col_sums[100];
    for (int j = 0; j < m; ++j) {
        col_sums[j] = 0.0;
        for (int i = 0; i < n; ++i) {
            col_sums[j] += A[i][j];
        }
    }

    for (int i = 0; i < m - 1; ++i) {
        for (int j = 0; j < m - 1 - i; ++j) {
            if (col_sums[j] > col_sums[j + 1]) {
                std::swap(col_sums[j], col_sums[j + 1]);
                for (int r = 0; r < n; ++r) {
                    std::swap(A[r][j], A[r][j + 1]);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
