#include <iostream>
#include "circle.h"

using namespace std;


int main()
{
	Circle *circle_mas[3];
	float r, x, y;
	float a, b, c;
	int target;
	int func_num;
	float result;
	bool check = true;
	setlocale(LC_ALL, "Russian");

	for (int i = 0; i < 3; i++)
	{
		cout << "Введите радиус и координаты ценра " << i + 1 << " окружности. Ввод через пробел." << endl;
		cin >> r >> x >> y;
		if(r > 0)
		{
			circle_mas[i] = new Circle(r, x, y);
		}
		else
		{	
			cout << "Радиус не может быть равен нулю. Введите другие данные " << endl << "->";
			cout << "Заново введите радиус и координаты центра окружности " << endl << "->";
			cin >> r >> x >> y;
			circle_mas[i] = new Circle(r, x, y);
			cout << "Данные исправлены" << endl;
		}
	}
	
	while (check == true)
	{
		cout << "Выберите окружность -> от 1 до 3. Для выхода из программы введите -> 0." << endl << "-> ";
		cin >> target;
		if (target - 1 < 0) break;
		if (target - 1 > 2)
		{
			cout << "Неверный номер окружности." << endl;
			continue;
		}
		cout << "Вы выбрали окружность № " << target << endl;
		while (true)
		{
			cout <<
				"Выберите функцию" << endl <<
				"0 - Выход из программы" << endl <<
				"1 - Задать параметры окружности" << endl <<
				"2 - Посчитать площадь окружности" << endl <<
				"3 - Можно ли описать окружность вокруг треугольника?" << endl <<
				"4 - Можно ли вписать окружность в треугольник?" << endl <<
				"5 - Проверка пересечения окружностей" << endl <<
				"6 - Выбрать другую окружность" << endl <<
				"-> ";
			cin >> func_num;

			if (func_num == 0)
			{
				 check = false;
				 break;
			}

			if (func_num == 6)
			{
				 break;
			}

			switch (func_num)
			{
			case 1:
				cout << "Введите радиус и координаты центра окружности через пробел." << endl;
				cin >> r >> x >> y;
				circle_mas[target - 1]->set_circle(r, x, y);
				cout << "Данные заданы" << endl;
				break;

			case 2:
				cout << "Площадь окружности равна: " << circle_mas[target - 1]->square() << endl;
				break;


			case 3:
				cout << "Введите стороны треугольника через пробел." << endl;
				cin >> a >> b >> c;
				result = circle_mas[target - 1]->triangle_around(a, b, c);
				cout << "Ответ: " << (result ? "Да " : "Нет ") << endl;
				break;

			case 4:
				cout << "Введите стороны треугольника через пробел." << endl;
				cin >> a >> b >> c;
				result = circle_mas[target - 1]->triangle_in(a, b, c);
				cout << "Ответ: " << (result ? "Да " : "Нет ") << endl;
				break;

			case 5:
				cout << "Введите радиус и координаты центра окружности через пробел." << endl;
				cin >> r >> x >> y;
				result = circle_mas[target - 1]->check_circle(r, x, y);
				cout << "Ответ: " << (result ? "Пересекает " : "Не пересекает ") << endl;
				break;
			
			default:
				cout << "Ошибка";
				break;
			}

			cout << endl;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		delete circle_mas[i];
	}

}