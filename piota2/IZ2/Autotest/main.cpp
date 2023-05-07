// Индивидуальное задание №2 Вариант 18

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <limits>
#include <algorithm>

using namespace std;

// Полный алфавит, нужен для парсинга значений из файла
const char fullAlphabet[] = {'0', '1', '#', '=', 'X', 'Y', ' '};

// Структура описывающая машину Тьюринга
struct MT {
    vector<char> lenta;
    unsigned int curState = 1;
    int head = 1;
};

// Структура описывающая состояние автомата
struct State {
    char symbol; // Символ, который нужно записать на ленту
    char action; // влево - "<" | вправо - ">" | на месте - "."
    unsigned int next; // Номер следущкго состояния
};

// Функция реализации одного шага работы машины Тьюринга. Так же выводит текущее состояние машины Тьюринга, ленту и указатель для ленты
// Входные параметры: указатель на машину Тьюринга, указатель на состояние
void oneStep(struct MT *mt, struct State *state) {
    cout << "Текущее состояние: " << mt->curState << endl;
    string out, point;
    for (int i = 0; i < 7; ++i) point += ' ';
    for (char c: mt->lenta) {
        out += c;
        point += (mt->head == out.length() - 1) ? '^' : ' ';
    }
    cout << "Лента: " << out << endl;
    cout << point << endl;

    mt->lenta[mt->head] = state->symbol;
    if (state->action == '>') {
        mt->head++;
        if (mt->head == mt->lenta.size())
            mt->lenta.push_back(' ');
    } else if (state->action == '<') {
        mt->head--;
        if (mt->head == -1) {
            mt->lenta.insert(mt->lenta.begin(), ' ');
            mt->head = 0;
        }
    } else if (state->action == '.') {
        mt->head = mt->head;
    }
}

// Функция проверки входной последовательности на соответствие алфавиту
// Входные параметры: указатель на входную последовательность
// Выход: true - если соответствует алфавиту, false - если не соответствует алфавиту
bool inputIsValid(string &input) {

    // Проверка на равенство количества символов слева от # и справа от #
    if (input.substr(0, input.find('#')).length() != input.substr(input.find('#') + 1, input.length() - 1).length())
        return false;

    // Проверка на пустую строку и наличие символа #
    if (input.length() == 0 || input.find('#') == string::npos)
        return false;

    // Проверка на соответствие входному алфавиту
    for (char i: input)
        if (!(i == '0' || i == '1' || i == '#'))
            return false;

    return true;
}

// Функция инициализации состояний, считывает состояния из .csv файла
// Входные параметры: указатель на вектор состояний
// Выход: false - если файл не удалось открыть, true - если файл открыт успешно
bool initStates(map<int, map<char, State>> &states) {
    string line, word;

    fstream file("andTuringMachine.csv", ios::in);
    if (file.is_open()) {
        int s = 1;
        while (getline(file, line)) {
            int curChar = 0;
            map<char, State> tmp_state;
            stringstream str(line);
            while (getline(str, word, ',')) {
                if (word.length() > 0) {
                    char action = ' ';
                    if (word.find('<') != string::npos)
                        action = '<';
                    else if (word.find('>') != string::npos)
                        action = '>';
                    else if (word.find('.') != string::npos)
                        action = '.';

                    if (action == ' ')
                        return false;

                    State st{};
                    st.symbol = word.substr(0, word.find(action))[0];
                    if (st.symbol == '_')
                        st.symbol = ' ';
                    st.action = action;
                    st.next = stoi(word.substr(word.find(action) + 1, word.length() - 1));
                    tmp_state.emplace(fullAlphabet[curChar++], st);
                } else
                    curChar++;
            }

            states.emplace(s++, tmp_state);
        }
        return true;
    }

    return false;
}


std::string to_binary_string(unsigned int n)
{
    std::string buffer; // символы ответа в обратном порядке
    // выделим память заранее по максимуму
    buffer.reserve(std::numeric_limits<unsigned int>::digits);
    do
    {
        buffer += char('0' + n % 2); // добавляем в конец
        n = n / 2;
    } while (n > 0);
    string res = std::string(buffer.crbegin(), buffer.crend()); // разворачиваем результат
    if (res.length() < 4) {
        string tmp;
        for (int i = 0; i < 4 - res.length(); ++i) {
            tmp += '0';
        }
        tmp += res;
        return tmp;
    }
    return res;
}

int main() {
    system("chcp 65001");

    map<int, map<char, State>> states;

    if (!initStates(states)) {
        cout << "Не удалось открыть файл с состояниями!\n\nНажмите enter для выхода из программы...";
        cin.get();
        return 0;
    }
    
    int input;

    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
        MT machine;

        string in;
        in = to_binary_string(i) + "#" + to_binary_string(j);

        if (!inputIsValid(in)) {
            cout << "Ваш ввод не коректен, проверьте алфавит и наличие символов!\n1 - Повтор ввода; Иное - Выход из программы:";
            cin >> input;
            if (input == 1) {
                in = "";
                continue;
            } else
                return 0;
        }

        machine.lenta.push_back(' ');
        for (char c: in) {
            machine.lenta.push_back(c);
        }
        machine.lenta.push_back(' ');

        cout << "Начальное состояние: 1\nНачальная лента: 1" << in << "\n";

        // Начало работы машины Тьюринга
        while (machine.curState != 0) {
            unsigned int next = states[machine.curState][machine.lenta[machine.head]].next;
            oneStep(&machine, &states[machine.curState][machine.lenta[machine.head]]);
            machine.curState = next;
        }


        string out, inc = to_binary_string(i) + "#" + to_binary_string(j) + "=" + to_binary_string(i | j);
        for (char c : machine.lenta) {
            if (c == '1' || c == '0' || c == '#' || c == '=')
            out+=c;
        }
            cout << "Лента:   \"" << out << "\"" << endl;
            cout << "Автотест: ";
        std::replace(out.begin(), out.end(), ' ', '\0');
        if (inc == out) {
            cout << "Логическое соотвествие" << endl;
        }
        else {
            cout << "Неудачно" << endl;
            cout << "Должно быть: \"" << inc << "\"" << endl;
            cout << "Что имеем:   \"" << out << "\"" << endl;
        }
        cout << endl;


    }}
}
