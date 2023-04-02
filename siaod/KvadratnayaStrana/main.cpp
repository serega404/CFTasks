#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int k;
    cin >> k;
    int cache[k];
    fill(cache, cache + k + 1, sqrt(k)+2);
    cache[0] = 0;
    for (int i = 1; i <= sqrt(k); i++) {
        int prc = i * i;
        for (int j = prc; j <= k; j++) {
            cache[j] = min(cache[j], cache[j - prc] + 1);
        }
    }
    cout << cache[k] << endl;

    return 0;
}
