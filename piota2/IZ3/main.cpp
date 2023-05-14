// Индивидуальное задание №3 Вариант 2.7

#include <iostream>

using namespace std;

// Функция рекурсии
// Входные данные: x1 - первое значение, x2 - второе значение
// Выходные данные: результат выполнения формулы
long recursion(int x1, int x2) {
    if (x1 == 0) {
        cout << "f(0," << x2 << ") = g(" << x2 << ") = 0\n";
        return 0;
    }
    long cur = recursion(x1 -  1, x2);
    cout << "f(" << x1 << "," << x2 << ") = h(" << x1 - 1 << ",f(" << x1 - 1 << "," << x2 << ")," << x2 << ") = h(" << x1 - 1 << "," << cur << "" << x2 << ") = " << x1 + cur << "\n";
    return x1 + cur;
}

int main() {
    system("chcp 65001");

    int x1, x2;
    cout << "Схема рекурсии:\nf(0,x2) = g(x2) = 0\nf(x1+1,x2) = h(x1,f(x1,x2),x2) = x2 + f(x1,x2) + 1\n\n";

    while (true) {
        cout << "Введите значение x1 и x2:";
        cin >> x1 >> x2;

        recursion(x1, x2);

        cout << "1 - Повтор ввода; Иное - Выход из программы:";
        cin >> x1;
        if (x1 != 1) return 0;
    }
}
