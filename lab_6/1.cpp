// Умова:
// Задано масив дійсних чисел A[n], n <= 200. Розробити програму, яка
// записує в масив B[n] по одному разу всі повторювані числа в масиві
// A[n]. Виводить повідомлення, якщо таких чисел немає.

#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Введіть розмірність масиву n (n <= 200): ";
    cin >> n;

    if (n <= 0 || n > 200) {
        cout << "Некоректний розмір масиву!" << endl;
        return 0;
    }

    // Створення динамічних масивів
    double* A = new double[n];
    double* B = new double[n];
    int b_count = 0;

    cout << "Введіть " << n << " дійсних чисел:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Пошук повторюваних елементів
    for (int i = 0; i < n; i++) {
        // Перевіряємо, чи ми вже не додавали це число до масиву B
        bool already_in_B = false;
        for (int k = 0; k < b_count; k++) {
            if (B[k] == A[i]) {
                already_in_B = true;
                break;
            }
        }

        if (already_in_B) {
            continue;
        }

        // Рахуємо кількість входжень A[i] у всьому масиві
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (A[j] == A[i]) {
                count++;
            }
        }

        // Якщо число зустрічається більше 1 разу — записуємо в B
        if (count > 1) {
            B[b_count++] = A[i];
        }
    }

    // Виведення результату
    if (b_count == 0) {
        cout << "Повторюваних чисел немає" << endl;
    } else {
        cout << "Повторювані числа: ";
        for (int i = 0; i < b_count; i++) {
            cout << B[i] << " ";
        }
        cout << endl;
    }

    // Звільнення динамічної пам'яті
    delete[] A;
    delete[] B;

    return 0;
}
