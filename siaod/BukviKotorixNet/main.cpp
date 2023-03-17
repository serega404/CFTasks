#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    a += b;
    b = "";

    sort(a.begin(), a.end());

    for (int i = 65; i <= 90; i++) {
        if (!binary_search(a.begin(), a.end(), i) && !binary_search(a.begin(), a.end(), i + 32))
            b += char(i);
    }

    if (b.length() != 0)
        cout << b;
    else
        cout << 0;

    return 0;
}
