#include <iostream>
#include <queue>

using namespace std;

int main() {
    int m, n, k, steps = 0;
    cin >> n >> m >> k;

    vector<vector<bool>> field(n, vector<bool>(m, false));

    queue<pair<int, int>> q;

    int x, y;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        field[x-1][y-1] = true;
        q.emplace(x-1, y-1);
    }

    for (;!q.empty();steps++) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            x = q.front().first, y = q.front().second;
            q.pop();

            // left
            if (x > 0 && !field[x - 1][y]) {
                field[x - 1][y] = true;
                q.emplace(x - 1, y);
            }

            // right
            if (x < n - 1 && !field[x + 1][y]) {
                field[x + 1][y] = true;
                q.emplace(x + 1, y);
            }

            // down
            if (y > 0 && !field[x][y - 1]) {
                field[x][y - 1] = true;
                q.emplace(x, y - 1);
            }

            // up
            if (y < m - 1 && !field[x][y + 1]) {
                field[x][y + 1] = true;
                q.emplace(x, y + 1);
            }
        }
    }

    cout << steps - 1;
    return 0;
}
