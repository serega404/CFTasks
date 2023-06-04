#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("INPUT.TXT");
    string alp;
    fin >> alp;
    pair<int, int> arr[alp.size()];

    for (int i = 0; i < alp.size(); ++i) {
        arr[i].first = i+1;
        arr[i].second = alp[i] - 'A'+1;
    }

    sort(&arr[0], &arr[alp.size()], [](pair<int, int> a, pair<int, int> b) { return b.second > a.second;});

    ofstream fout("OUTPUT.TXT");

    for(int i = 0; i < alp.size(); ++i){
        if(arr[i].second <= i){
            fout << "NO" << endl;
            return 0;
        }
    }

    fout << "YES" << endl;
    for (int i = 0; i < alp.size(); ++i) {
        fout << arr[i].first << " ";
    }

    return 0;
}