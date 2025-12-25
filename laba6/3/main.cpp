#include <iostream>
#include "za3.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    double x1, y1, z1, x2, y2, z2;

    cout << "Введите первую точку (X Y Z): ";
    cin >> x1 >> y1 >> z1;

    cout << "Введите вторую точку (X Y Z): ";
    cin >> x2 >> y2 >> z2;

    Point3D p1(x1, y1, z1);
    Point3D p2(x2, y2, z2);

    cout << "\nТочка 1: ";
    p1.Print();

    cout << "Точка 2: ";
    p2.Print();

    cout << "Расстояние: " << p1.Distance(p2) << endl;

    return 0;
}
