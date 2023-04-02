#include <fstream>

using namespace std;

int main() {
    ifstream fin("INPUT.TXT");
    ofstream fout("OUTPUT.TXT");
    int n;
    fin >> n;
    int platforms[n], energy_stp[n];
    energy_stp[0] = 0;

    for (int i = 0; i < n; ++i) {
        fin >> platforms[i];
    }

    energy_stp[1] = abs(platforms[1] - platforms[0]);
    for (int i = 2; i < n; ++i) {
        energy_stp[i] = min(energy_stp[i-2] + 3 * abs(platforms[i] - platforms[i - 2]),
                            energy_stp[i-1] + abs(platforms[i] - platforms[i - 1]));
    }

    fout << energy_stp[n - 1];

    return 0;
}
