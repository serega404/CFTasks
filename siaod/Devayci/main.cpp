#include <iostream>
#include <map>

using namespace std;

int main() {
    string fName, dName;
    int price;
    map<string, int> deviceCount;
    map<string, int> devicePrice;

    for (int i = 0; i < 6; ++i) {
        cin >> fName >> dName >> price;
        deviceCount[dName] += 1;
        devicePrice[dName] = price < devicePrice[dName] || devicePrice[dName] == 0 ? price : devicePrice[dName];
    }

    int max = 0;
    for (const auto& device : deviceCount) {
        if (device.second > max) {
            max = device.second;
            dName = device.first;
        } else if (device.second == max) {
            if (devicePrice[device.first] < devicePrice[dName]) {
                dName = device.first;
            }
        }
    }

    cout << dName << endl;

    return 0;
}
