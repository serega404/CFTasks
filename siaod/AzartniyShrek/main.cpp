#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("INPUT.TXT");
    int N;
    fin >> N;
    int arr[N];
    for (int i = 0; i < N; ++i)
        fin >> arr[i];

    sort(&arr[0], &arr[N], [](int a, int b) { return a > b; });

    int sumA = 0, sumB = 0;
    for (int i = 0; i < N/2; ++i) {
        sumA += arr[i];
        sumB += arr[N-1-i];
    }

    ofstream fout("OUTPUT.TXT");
    fout << sumA - sumB;

    return 0;
}