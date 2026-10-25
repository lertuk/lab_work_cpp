#include <iostream>

int main() {
    int n;
    std::cin >> n;

    if (n <= 0 || n > 200) {
        return 0;
    }

    double A[200];
    for (int i = 0; i < n; ++i) {
        std::cin >> A[i];
    }

    double B[200];
    int b_count = 0;

    for (int i = 0; i < n; ++i) {
        bool already_in_b = false;
        for (int k = 0; k < b_count; ++k) {
            if (B[k] == A[i]) {
                already_in_b = true;
                break;
            }
        }

        if (already_in_b) {
            continue;
        }

        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (A[j] == A[i]) {
                ++count;
            }
        }

        if (count > 1) {
            B[b_count++] = A[i];
        }
    }

    if (b_count == 0) {
        std::cout << "Повторюваних чисел немає" << std::endl;
    } else {
        for (int i = 0; i < b_count; ++i) {
            std::cout << B[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
