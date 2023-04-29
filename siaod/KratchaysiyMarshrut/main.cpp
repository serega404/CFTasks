#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int N, A, B;
    cin >> N;

    vector<vector<int>> vesa(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> vesa[i][j];

    cin >> A >> B;

    vector<int> dist(N, INT_MAX), parent(N, -1);
    dist[A - 1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> queue1;
    queue1.emplace(0, A - 1);

    while (!queue1.empty()) {
        int u = queue1.top().second;
        queue1.pop();

        for (int i = 0; i < N; i++)
            if (vesa[u][i] != 0 && dist[u] + vesa[u][i] < dist[i]) {
                dist[i] = dist[u] + vesa[u][i];
                parent[i] = u;
                queue1.emplace(dist[i], i);
            }
    }

    if (dist[B - 1] != INT_MAX)
    {
        cout << dist[B - 1] << endl;
        vector<int> path;

        for (int i = B - 1; i != -1; i = parent[i])
            path.push_back(i);

        for (int i = path.size() - 1; i >= 0; i--)
            cout << path[i] + 1 << " ";
        cout << endl;
    } else
        cout << 0 << endl;

    return 0;
}