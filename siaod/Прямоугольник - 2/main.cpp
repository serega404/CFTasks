#include <iostream>

using namespace std;

int main()
{
    int x[4], y[4];
    cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
    int v1 = (x[1] - x[0]) * (x[1] - x[0]) + (y[1] - y[0]) * (y[1] - y[0]);
    int v2 = (x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2]);
    int v3 = (x[2] - x[0]) * (x[2] - x[0]) + (y[2] - y[0]) * (y[2] - y[0]);

    if (v2 > v1 && v2 > v3)
    {
        swap(x[1], x[0]);
        swap(y[1], y[0]);
    }
    if (v1 > v2 && v1 > v3)
    {
        swap(x[1], x[2]);
        swap(y[2], y[1]);
    }

    x[3] = x[0] - x[1] + x[2];
    y[3] = y[0] - y[1] + y[2];

    cout << x[3] << " " << y[3];

    return 0;
}
