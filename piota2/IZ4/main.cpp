// Индивидуальное задание №4 Вариант 3.15

#include <iostream>
#include <map>

using namespace std;

// Структура описывающая подстановку
struct podstanovka
{
    string obrazec;
    string zamena;
};

// Функция проверки входного слова на соответствие алфавиту
// Входные параметры: указатель на строку с входным словом
// Выход: true - если соответствует алфавиту, false - если не соответствует алфавиту
bool inputIsValid(string &input)
{

    // Проверка на соответствие входному алфавиту
    for (char i : input)
        if (!(i == 'a' || i == 'b' || i == 'c' || i == 'd' || i == 'e' || i == 'f'))
            return false;

    return true;
}

// Функкция одного шага работы алгоритма
// Входные параметры: указатель на строку с входным словом, указатель на массив подстановок
// Выход: true - если алгоритм завершил работу (успешно или с ошибкой), false - если алгоритм ещё не завершил работу
bool isEnded(string &slovo, map<int, podstanovka> &podstanovki)
{
    for (auto &podstanovka : podstanovki)
    {
        if (slovo.find(podstanovka.second.obrazec) != string::npos)
        {
            string pointers = "    ";

            pointers += podstanovka.first >= 10 ? " " : "";
            for (size_t i = 0; i < slovo.find(podstanovka.second.obrazec); i++)
                pointers += " ";
            for (size_t i = 0; i < podstanovka.second.obrazec.length(); i++)
                pointers += "^";

            cout << "(" << podstanovka.first << ") " << slovo << " -> ";

            slovo.replace(slovo.find(podstanovka.second.obrazec), podstanovka.second.obrazec.length(), podstanovka.second.zamena);

            // Если происходит замена на точку, алгоритм завершает работу 
            if (podstanovka.second.zamena == ".") {
                slovo.erase(slovo.find("."), 1);
                cout << slovo << endl << pointers << endl;
                cout << "Результат: " << slovo << endl;
                return true;
            }

            cout << slovo << endl << pointers << endl;

            return false;
        }
    }

    cout << "Ошибка системы подстановок!\n";
    return true;
}

// Функция инициализации массива подстановок
// Входные параметры: указатель на массив подстановок
void initPodstanovki(map<int, podstanovka> &podstanovki) {
    podstanovki.insert({1, {"#a", "aa*"}});
    podstanovki.insert({2, {"#b", "bb*"}});
    podstanovki.insert({3, {"#c", "cc*"}});
    podstanovki.insert({4, {"#d", "dd*"}});
    podstanovki.insert({5, {"#e", "ee*"}});
    podstanovki.insert({6, {"#f", "ff*"}});
    podstanovki.insert({7, {"*a", "a#"}});
    podstanovki.insert({8, {"*b", "b#"}});
    podstanovki.insert({9, {"*c", "c#"}});
    podstanovki.insert({10, {"*d", "d#"}});
    podstanovki.insert({11, {"*e", "e#"}});
    podstanovki.insert({12, {"*f", "f#"}});
    podstanovki.insert({13, {"*", "."}});
    podstanovki.insert({14, {"#", "."}});
    podstanovki.insert({15, {" ", "*"}});
}

int main()
{
    system("chcp 65001");

    string slovo;
    map<int, podstanovka> podstanovki;

    initPodstanovki(podstanovki);

    while (true)
    {
        cout << "Введите входное слово:";
        cin >> slovo;

        if (!inputIsValid(slovo))
        {
            cout << "Введённая последовательность не соответствует алфавиту!\n1 - Повтор ввода; Иное - Выход из программы:";
            cin >> slovo;
            if (slovo == "1")
                continue;
            else
                return 0;
        }

        slovo = " " + slovo;

        while (!isEnded(slovo, podstanovki));

        cout << "1 - Повтор ввода; Иное - Выход из программы:";
        cin >> slovo;
        if (slovo != "1")
            return 0;
    }
}
