// Умова:
// Задано масив дійсних чисел A[n], n <= 200. Розробити програму, яка
// записує в масив B[n] по одному разу всі повторювані числа в масиві
// A[n]. Виводить повідомлення, якщо таких чисел немає.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Введіть розмірність вектора n (n <= 200): ";
    cin >> n;

    if (n <= 0 || n > 200) {
        cout << "Некоректний розмір вектора!" << endl;
        return 0;
    }

    vector<double> A(n);
    vector<double> B;

    cout << "Введіть " << n << " дійсних чисел:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        // Перевіряємо, чи елемент уже є в векторі B
        bool already_in_B = false;
        for (double val : B) {
            if (val == A[i]) {
                already_in_B = true;
                break;
            }
        }

        if (already_in_B) {
            continue;
        }

        // Рахуємо кількість повторень елемента
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (A[j] == A[i]) {
                count++;
            }
        }

        if (count > 1) {
            B.push_back(A[i]);
        }
    }

    // Виведення результату
    if (B.empty()) {
        cout << "Повторюваних чисел немає" << endl;
    } else {
        cout << "Повторювані числа: ";
        for (double val : B) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
