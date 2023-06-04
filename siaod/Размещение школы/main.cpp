#include <iostream>
#include <vector>

using namespace std;

const int INF = 99999999;
int main() {
    int n;
    cin >> n;

    vector<vector<int>> distance(n, vector<int>(n));
    vector<int> pupils(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> distance[i][j];
            if (distance[i][j] == 0 && i != j) distance[i][j] = INF;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int l = 0; l < n; l++)
                distance[j][l] = min(distance[j][l], distance[j][i] + distance[i][l]);

    for (int i = 0; i < n; i++)
        cin >> pupils[i];

    int min_distance = INF, par = -1;
    for (int i = 0; i < n; i++) {
        int dis = 0;
        for (int j = 0; j < n; j++) {
            if (distance[i][j] < INF)
                dis += distance[i][j] * pupils[j];
            else
                dis += 10000 * pupils[j];
        }
        if (dis < min_distance) {
            min_distance = dis;
            par = i;
        }
    }

    cout << par + 1 << " " << min_distance;

    return 0;
}