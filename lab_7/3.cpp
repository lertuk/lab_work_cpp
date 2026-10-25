// Умова:
// Нехай x0 = 1, xi = x_{i-1} + 2*i, де i = 1, 2, ...
// Визначити x10 за допомогою підпрограми (рекурсивної або ітеративної).

#include <iostream>

using namespace std;

// Рекурсивна підпрограма для обчислення x_i
int get_x(int i) {
    if (i == 0) {
        return 1;
    }
    return get_x(i - 1) + 2 * i;
}

int main() {
    int result = get_x(10);

    cout << "x10 = " << result << endl;

    return 0;
}
