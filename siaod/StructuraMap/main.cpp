#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> clients;
    string name;
    int action, n, money;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> action;
        if (action == 1) {
            cin >> name >> money;
            clients[name] += money;
        } else if (action == 2) {
            cin >> name;
            if (clients.find(name) == clients.end())
                cout << "ERROR" << endl;
            else
                cout << clients[name] << endl;
        }
    }

    return 0;
}
