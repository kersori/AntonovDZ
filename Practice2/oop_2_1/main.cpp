#include "eq2.h"

using namespace std;

int main()
{
    double a, b, c;
    setlocale(LC_ALL, "Russian");

    cout << "Введите коэффициенты a, b, c квадратного уравнения (через пробел): " << endl << "-> ";
    cin >> a >> b >> c;
    eq2 exmpl(a, b, c);
    exmpl.set(a, b, c);
    cout << "Y равен: " << exmpl.find_Y(exmpl.find_X()) << endl;
    cout << "Введите коэффициенты уравнения для сложения с предыдущим (через пробел): " << endl;
    cin >> a >> b >> c;
    eq2 exmpl1(a, b, c);
    exmpl1.set(a, b, c);
    eq2 sum = exmpl + exmpl1;
    sum.Out();
}

