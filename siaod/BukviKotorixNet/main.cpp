#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    a += b;

    set<char> chars;

    for (char c: a)
        chars.insert(c);

    bool fail = true;
    for (int i = 65; i <= 90; i++) {
        if (!binary_search(chars.begin(), chars.end(), i) && !binary_search(chars.begin(), chars.end(), i + 32)) {
            cout << char(i);
            fail = false;
        }

    }

    if (fail)
        cout << 0;

    return 0;
}
