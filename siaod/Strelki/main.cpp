#include <iostream>

using namespace std;

int main()
{
    unsigned int count = 0;
    string s;
    cin >> s;
    if (s.size() > 4)
        for (int i = 0; i < s.size() - 4; ++i)
            if (s.substr(i, 5) == ">>-->" || s.substr(i, 5) == "<--<<")
                count++;
    cout << count;
    return 0;
}
