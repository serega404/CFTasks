#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, out = 0;
    cin >> N >> M;

    vector<vector<int>> a(N, vector<int>(N, 999999));
    vector<vector<int>> b(N, vector<int>(N, 999999));

    int s, e, l;
    for (int i = 0; i < M; i++) {
        cin >> s >> e >> l;
        a[s-1][e-1] = a[e-1][s-1] = l;
    }

    for (int k = 0; k < N; k++) {
        a[k][k] = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                b[i][j] = min(a[i][k] + a[k][j], a[i][j]);
        swap(a, b);
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (a[i][j] != 999999)
                out = max(a[i][j], out);
    cout << out;

    return 0;
}