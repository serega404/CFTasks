// Индивидуальное задание №1 Вариант 20

#include <iostream>
#include <vector>
#include <array>

using namespace std;

using States = array<int[3], 7>;

// Фунция инициализации автомата
// Выход: массив состояний автомата
States init_automate() {
    return {{
        //   0, 1, 2 Переходы
            {0, 1, 2},  //  q0
            {3, 4, 5},  //  q1
            {6, 0, 1},  //  q2
            {2, 3, 4},  //  q3
            {5, 6, 0},  //  q4
            {1, 2, 3},  //  q5
            {4, 5, 6},  //  q6
    }};
}

// Функция проверки входной последовательности на соответствие алфавиту
// Входные параметры: указатель на входную последовательность, указатель на массив состояний автомата
// Выход: true - если соответствует алфавиту, false - если не соответствует алфавиту
bool inputIsValid(string &input, vector<int> &sequence) {
    for (char i : input) {
        if (i == '0' || i == '1' || i == '2')
            sequence.push_back(i - '0');
        else {
            sequence.clear();
            return false;
        }
    }
    return true;
}

// Функция получения следующего состояния автомата и вывода информации о переходе
// Входные параметры: массив состояний автомата, текущее состояние, входной символ
// Выход: следующее состояние автомата
int getNextState(States &automate, int &state, bool isOne) {
    cout << isOne << " q" << state << " -> q" << automate[state][isOne] << "\n";
    return automate[state][isOne];
}

int main() {
    system("chcp 65001");

    States automate = init_automate();
    int input;

    while (true) {

        int curState = 0;
        vector<int> sequence;

        cout << "Введите входную последовательность:";
        string in;
        cin >> in;

        if (!inputIsValid(in, sequence)) {
            cout << "Введённая последовательность не соответствует алфавиту!\n1 - Повтор ввода; Иное - Выход из программы:";
            cin >> input;
            if (input == 1) {
                in = "";
                continue;
            } else
                return 0;
        }

        for (auto i : sequence)
            curState = getNextState(automate, curState, i);

        if (curState != 0)
            cout << "Yes\n";
        else
            cout << "No\n";

        cout << "1 - Повтор ввода; Иное - Выход из программы:";
        cin >> input;
        if (input != 1)
            return 0;
    }
}
