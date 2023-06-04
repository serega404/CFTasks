#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int gvozdi[n], cache[n];
    fill(cache, cache + n, 0);
    for (int i = 0; i < n; i++)
        cin >> gvozdi[i];

    sort(gvozdi, gvozdi + n);

    cache[0] = gvozdi[1] - gvozdi[0];
    cache[1] = gvozdi[2] - gvozdi[0];

    n -= 2;
    for (int i = 2; i <= n; i++)
        cache[i] = gvozdi[i+1] - gvozdi[i] + min(cache[i - 1], cache[i - 2]);

    cout << cache[n] << endl;
}