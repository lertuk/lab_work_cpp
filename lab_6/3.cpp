// Умова:
// Дано двовимірний масив дійсних чисел A[n][m]. Написати програму,
// що переформовує масив A[n][m] таким чином, щоб його стовбці
// розташувались в порядку зростання їх поелементних сум.

#include <iostream>
#include <utility>

using namespace std;

int main() {
    int n, m;
    cout << "Введіть кількість рядків n та стовпців m: ";
    cin >> n >> m;

    if (n <= 0 || m <= 0) {
        cout << "Некоректні розміри матриці!" << endl;
        return 0;
    }

    // Виділення динамічної пам'яті під двовимірний масив n x m
    double** A = new double*[n];
    for (int i = 0; i < n; i++) {
        A[i] = new double[m];
    }

    cout << "Введіть елементи матриці:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    // Обчислення сум кожного стовпця
    double* col_sums = new double[m];
    for (int j = 0; j < m; j++) {
        col_sums[j] = 0.0;
        for (int i = 0; i < n; i++) {
            col_sums[j] += A[i][j];
        }
    }

    // Сортування стовпців бульбашкою за зростанням їх сум
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - 1 - i; j++) {
            if (col_sums[j] > col_sums[j + 1]) {
                swap(col_sums[j], col_sums[j + 1]);
                for (int r = 0; r < n; r++) {
                    swap(A[r][j], A[r][j + 1]);
                }
            }
        }
    }

    // Виведення відсортованого масиву
    cout << "Матриця після впорядкування стовпців:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    // Звільнення виділеної динамічної пам'яті
    delete[] col_sums;
    for (int i = 0; i < n; i++) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
