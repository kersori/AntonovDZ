#include "figure.h"

using namespace std;

int main()
{
    float Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
    setlocale(LC_ALL, "Russian");

    cout << "Введите координаты вершины А четырёхугольника №1 (через пробел): ";
    cin >> Ax >> Ay;
    cout << "Введите координаты вершины B четырёхугольника №1 (через пробел): ";
    cin >> Bx >> By;
    cout << "Введите координаты вершины C четырёхугольника №1 (через пробел): ";
    cin >> Cx >> Cy;
    cout << "Введите координаты вершины D четырёхугольника №1 (через пробел): ";
    cin >> Dx >> Dy;
    cout << endl;

    figure *fig1 = new figure(Ax, Bx, Cx, Dx, Ay, By, Cy, Dy);

    cout << "Введите координаты вершины А четырёхугольника №2 (через пробел): ";
    cin >> Ax >> Ay;
    cout << "Введите координаты вершины B четырёхугольника №2 (через пробел): ";
    cin >> Bx >> By;
    cout << "Введите координаты вершины C четырёхугольника №2 (через пробел): ";
    cin >> Cx >> Cy;
    cout << "Введите координаты вершины D четырёхугольника №2 (через пробел): ";
    cin >> Dx >> Dy;
    cout << endl;

    figure *fig2 = new figure(Ax, Bx, Cx, Dx, Ay, By, Cy, Dy);

    cout << "Введите координаты вершины А четырёхугольника №3 (через пробел): ";
    cin >> Ax >> Ay;
    cout << "Введите координаты вершины B четырёхугольника №3 (через пробел): ";
    cin >> Bx >> By;
    cout << "Введите координаты вершины C четырёхугольника №3 (через пробел): ";
    cin >> Cx >> Cy;
    cout << "Введите координаты вершины D четырёхугольника №3 (через пробел): ";
    cin >> Dx >> Dy;
    cout << endl;

    figure *fig3 = new figure(Ax, Bx, Cx, Dx, Ay, By, Cy, Dy);

    if (fig1->is_prug())
    {
        cout << "Четырёхугольник 1 - прямоугольник" << endl;
    }

    if (fig2->is_prug())
    {
        cout << "Четырёхугольник 2 - прямоугольник" << endl;
    }
    if (fig3->is_prug())
    {
        cout << "Четырёхугольник 3 - прямоугольник" << endl;
    }
    cout << endl;

    if (fig1->is_romb())
    {
        cout << "Четырёхугольник 1 - ромб" << endl;
    }
    if (fig2->is_romb())
    {
        cout << "Четырёхугольник 2 - ромб" << endl;
    }
    if (fig3->is_romb())
    {
        cout << "Четырёхугольник 3 - ромб" << endl;
    }
    cout << endl;

    if (fig1->is_square())
    {
        cout << "Четырёхугольник 1 - квадрат" << endl;
    }

    if (fig2->is_square())
    {
        cout << "Четырёхугольник 2 - квадрат" << endl;
    }
    if (fig3->is_square())
    {
        cout << "Четырёхугольник 3 - квадрат" << endl;
    }
    cout << endl;

    if (fig1->is_in_circle())
    {
        cout << "В четырёхугольник 1 можно вписать окружность" << endl;
    }
    if (fig2->is_in_circle())
    {
        cout << "В четырёхугольник 2 можно вписать окружность" << endl;
    }
    if (fig3->is_in_circle())
    {
        cout << "В четырёхугольник 3 можно вписать окружность" << endl;
    }
    cout << endl;

    if (fig1->is_out_circle())
    {
        cout << "Вокруг четырёхугольника 1 можно описать окружность" << endl;
    }
    if (fig2->is_out_circle())
    {
        cout << "Вокруг четырёхугольника 2 можно описать окружность" << endl;
    }
    if (fig3->is_out_circle())
    {
        cout << "Вокруг четырёхугольника 3 можно описать окружность" << endl;
    }
    cout << endl;

    fig1->show();
    cout << endl;
    fig2->show();
    cout << endl;
    fig3->show();
    cout << endl;

    delete fig1, fig2, fig3;
}

