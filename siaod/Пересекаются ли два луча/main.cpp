#include <iostream>
 
using namespace std;
 
int main()
{
    int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;
    double cAB, cCD, opr = Ay * (Dx - Cx) + By * (-Dx + Cx) + (Bx - Ax) * (Dy - Cy);
    if (opr == 0)
        // Проверяем совпадение лучей + смотрят ли лучи в одном направлении
        if (((Cx - Ax) * (By - Ay) == (Cy - Ay) * (Bx - Ax)) &&
            ((Bx - Ax) * (Cx - Ax) >= 0 && (By - Ay) * (Cy - Ay) >= 0))
                cout << "YES";
        else if (((Ax - Cx) * (Dy - Cy) == (Ay - Cy) * (Dx - Cx)) &&
            ((Dx - Cx) * (Ax - Cx) >= 0 && (Dy - Cy) * (Ay - Cy) >= 0))
                cout << "YES";
        else
            cout << "NO";
    else
    {
        cAB = (Ay * (Dx - Cx) + Dy * Cx - Dx * Cy + Ax * (-Dy + Cy)) / opr;
        cCD = (-Ay * Cx + By * (-Ax + Cx) + Bx * (Ay - Cy) + Ax * Cy) / opr;
        if (cAB >= 0 && cCD >= 0)
            cout << "YES";
        else
            cout << "NO";
    }

    return 0;
}