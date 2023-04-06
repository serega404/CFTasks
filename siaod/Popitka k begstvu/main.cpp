#include <iostream>

using namespace std;

int main() {

    int n, m, tmp;
    cin >> n >> m;

    bool a[n + 1][m + 1];
    int a_int[n + 1][m + 1];
    fill_n(&a[0][0], (n + 1) * (m + 1), false);
    fill(&a_int[0][0], &a_int[0][0] + (n + 1) * (m + 1), 0);

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++) {
            cin >> tmp;
            a[i][j] = tmp == 1;
        }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (a[i][j])
                a_int[i][j] = a_int[i][j - 1] + a_int[i - 1][j];

            if (i == 1 && j == 1)
                a_int[1][1] = true;
        }
    }

    cout << (a_int[n][m] > 0 ? to_string(a_int[n][m]) : "Impossible");

    return 0;
}
