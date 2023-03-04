#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("INPUT.TXT");
    int N;
    fin >> N;
    short arr[N];
    for (int i = 0; i < N; ++i)
        fin >> arr[i];

    ofstream fout("OUTPUT.TXT");

    sort(&arr[0], &arr[N]);
    for (int i = 0; i < N; i++)
        if (i % 2 == 0) fout << arr[i] << ' ';
    for (int i = N-1; i > 0; i--)
        if (i % 2 != 0) fout << arr[i] << ' ';

    return 0;
}