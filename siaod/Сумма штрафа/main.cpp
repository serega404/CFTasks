#include <iostream>

using namespace std;

int main() {
    pair<double, double> a[3];
    int  n, sum = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i % 3].first >> a[i % 3].second;
        if (i >= 2) {
            if (a[(i - 2) % 3].first * (a[i % 3].second - a[(i - 1) % 3].second) +
                a[(i - 1) % 3].first * (a[(i - 2) % 3].second - a[i % 3].second) +
                a[i % 3].first * (a[(i - 1) % 3].second - a[(i - 2) % 3].second) < 0)
                sum++;
        }
    }

    cout << sum;
    return 0;
}