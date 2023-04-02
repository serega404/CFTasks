// Индивидуальное задание №1 Вариант 7

#include <iostream>
#include <vector>
#include <array>

using namespace std;

using States = array<int[2], 12>;

// Фунция инициализации автомата
// Выход: массив состояний автомата
States init_automate() {
    return {{
        //   0, 1 Переходы
            {3, 1},   //  q0
            {5, 2},   //  q1
            {8, 1},   //  q2
            {4, 5},   //  q3
            {6, 7},   //  q4
            {7, 8},   //  q5
            {3, 9},   //  q6
            {9, 10},  //  q7
            {10, 5},  //  q8
            {5, 11},  //  q9
            {11, 7}, //  q10
            {8, 9}   //  q11
    }};
}

// Функция проверки входной последовательности на соответствие алфавиту
// Входные параметры: указатель на входную последовательность, указатель на массив состояний автомата
// Выход: true - если соответствует алфавиту, false - если не соответствует алфавиту
bool inputIsValid(string &input, vector<bool> &sequence) {
    for (char i : input) {
        if (i == '0' || i == '1')
            sequence.push_back(i == '1');
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
        vector<bool> sequence;

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

        if (curState == 11)
            cout << "Yes\n";
        else
            cout << "No\n";

        cout << "1 - Повтор ввода; Иное - Выход из программы:";
        cin >> input;
        if (input != 1)
            return 0;
    }
}
