#include <iostream>
#include <vector>
#include <map>

using namespace std;

int find(int x, vector<int> &p) {
    if (x == p[x])
        return x;
    return p[x] = find(p[x], p);
}

void unite(int a, int b, vector<int> &p) {
    a = find(a, p);
    b = find(b, p);
    if (a != b)
        p[b] = a;
}

int main() {
    int n, m, vesmod = 0;
    cin >> n >> m;
    multimap<int, pair<int, int>> edges;
    vector<int> p;
    for (int i = 0; i < m; i++) {
        int b, e, w;
        cin >> b >> e >> w;
        edges.emplace(w, make_pair(b, e));
    }

    p.resize(n+1);
    for (int i = 0; i < n; i++)
        p[i] = i;

    for (auto e : edges) {
        if (find(e.second.first, p) != find(e.second.second, p)) {
            vesmod += e.first;
            unite(e.second.first, e.second.second, p);
        }
    }

    cout << vesmod << endl;

    return 0;
}

