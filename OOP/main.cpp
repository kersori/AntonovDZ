#include <iostream>
#include <vector>
#include <string>
#include "circle.h"
#include "square.h"
#include "rectangle.h"
#include "triangle.h"

using namespace std;


int main()
{	

	vector <Circle> circle_mas;
	circle_mas.push_back(Circle(5, 1, 1));
	circle_mas.push_back(Circle(10, 2, 2));
	circle_mas.push_back(Circle(20, 0, 0));

	vector <Triangle> triangle_mas;
	triangle_mas.push_back(Triangle(2, 3, 4));
	triangle_mas.push_back(Triangle(3, 4, 5));
	triangle_mas.push_back(Triangle(5, 2, 4));

	vector <Rectangle> rectangle_mas;
	rectangle_mas.push_back(Rectangle(1, 2));
	rectangle_mas.push_back(Rectangle(2, 2));
	rectangle_mas.push_back(Rectangle(3, 2));

	vector <Square> square_mas;
	square_mas.push_back(Square(1));
	square_mas.push_back(Square(2));
	square_mas.push_back(Square(3));

	float r, x, y;
	float a, b, c;
	int point;
	int target;
	int func_num;
	float result;
	bool check = true;
	int number;
	string color;
	setlocale(LC_ALL, "Russian");

	while (check == true)
	{
		cout <<
			"Введите номер класса фигур или функцию" << endl <<
			"0 - Выход из программы" << endl <<
			"1 - Окружность" << endl <<
			"2 - Треугольник" << endl <<
			"3 - Прямоугольник" << endl <<
			"4 - Квадрат" << endl <<
			"-> ";
		cin >> number;
		if (number > 4)
		{
			cout << "Неверный номер." << endl;
			continue;
		}
		if(number > 0)
		{	
			if(number == 1)
			{	
				for (int i = 0; i < circle_mas.size(); i++)
				{	
					cout << "Окружность №: " << i + 1 << endl;
				}
				cout <<  circle_mas.size() + 1 << " - Добавить новую окружность" << endl <<
				circle_mas.size() + 2 << " - Удалить одну из окружностей" << endl;
				cout << "Выберите окружность -> от 1 до " << circle_mas.size() << " или функцию. Для выхода из программы введите -> 0." << endl << "-> ";
				cin >> target;
				if (target - 1 < 0) break;
				if (target > circle_mas.size() + 2)
				{
					cout << "Неверный номер окружности." << endl;
					continue;
				}
				cout << "Вы выбрали № " << target << endl;

				if(target == circle_mas.size() + 1)
				{
					cout << "Введите радиус и координаты центра окружности через пробел." << endl;
					cin >> r >> x >> y;
					circle_mas.push_back(Circle(r, x, y));
					cout << "Данные заданы" << endl;
					continue;
				}
				if(target == circle_mas.size() + 2)
				{
					cout << "Введите номер окружности." << endl;
					cin >> point;
					circle_mas.erase(circle_mas.begin() + point - 1);
					cout << "Данные заданы" << endl;
					continue;
				}

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
						"6 - Узнать цвет" << endl <<
						"7 - Задать цвет" << endl <<
						"8 - Выбрать другую фигуру" << endl <<
						"-> ";
					cin >> func_num;

					if (func_num == 0)
					{
						check = false;
						break;
					}

					if (func_num == 8)
					{
						break;
					}

					switch (func_num)
					{
					case 1:
						cout << "Введите радиус и координаты центра окружности через пробел." << endl;
						cin >> r >> x >> y;
						circle_mas[target - 1].set_circle(r, x, y);
						cout << "Данные заданы" << endl;
						break;

					case 2:
						cout << "Площадь окружности равна: " << circle_mas[target - 1].square() << endl;
						break;


					case 3:
						cout << "Введите стороны треугольника через пробел." << endl;
						cin >> a >> b >> c;
						result = circle_mas[target - 1].triangle_around(a, b, c);
						cout << "Ответ: " << (result ? "Да " : "Нет ") << endl;
						break;

					case 4:
						cout << "Введите стороны треугольника через пробел." << endl;
						cin >> a >> b >> c;
						result = circle_mas[target - 1].triangle_in(a, b, c);
						cout << "Ответ: " << (result ? "Да " : "Нет ") << endl;
						break;

					case 5:
						cout << "Введите радиус и координаты центра окружности через пробел." << endl;
						cin >> r >> x >> y;
						result = circle_mas[target - 1].check_circle(r, x, y);
						cout << "Ответ: " << (result ? "Пересекает " : "Не пересекает ") << endl;
						break;
					
					case 6:
						
						cout << "Цвет фигуры: " << circle_mas[target - 1].get_color() << endl;
						break;

					case 7:
						cout << "Введите цвет." << endl;
						cin >> color;
						circle_mas[target - 1].set_color(color);
						cout << "Цвет фигуры: " << circle_mas[target - 1].get_color() << endl;
						break;
					
					default:
						cout << "Ошибка";
						break;
					}
					cout << endl;
				}
			}
			if(number == 2)
			{	
				for (int i = 0; i < triangle_mas.size(); i++)
				{	
					cout << "Треугольник №: " << i + 1 << endl;
				}
				cout <<  triangle_mas.size() + 1 << " - Добавить новый треугольник" << endl <<
				triangle_mas.size() + 2 << " - Удалить один из треугольников" << endl;
				cout << "Выберите треугольник -> от 1 до " << triangle_mas.size() << " или функцию. Для выхода из программы введите -> 0." << endl << "-> ";
				cin >> target;
				if (target - 1 < 0) break;
				if (target > triangle_mas.size() + 2)
				{
					cout << "Неверный номер треугольника." << endl;
					continue;
				}
				cout << "Вы выбрали № " << target << endl;

				if(target == triangle_mas.size() + 1)
				{
					cout << "Введите три стороны через пробел." << endl;
					cin >> a >> b >> c;
					triangle_mas.push_back(Triangle(a, b, c));
					cout << "Данные заданы" << endl;
					continue;
				}
				if(target == triangle_mas.size() + 2)
				{
					cout << "Введите номер треугольника." << endl;
					cin >> point;
					triangle_mas.erase(triangle_mas.begin() + point - 1);
					cout << "Данные заданы" << endl;
					continue;
				}

				while (true)
				{
					cout <<
						"Выберите функцию" << endl <<
						"0 - Выход из программы" << endl <<
						"1 - Задать параметры треугольника" << endl <<
						"2 - Посчитать площадь треугольника" << endl <<
						"3 - Посчитать периметр треугольника" << endl <<
						"4 - Выбрать другую фигуру" << endl <<
						//"4 - Узнать цвет" << endl <<
						//"5 - Задать цвет" << endl <<
						//"6 - Выбрать другую фигуру" << endl <<
						"-> ";
					cin >> func_num;

					if (func_num == 0)
					{
						check = false;
						break;
					}

					if (func_num == 4)
					{
						break;
					}

					switch (func_num)
					{
					case 1:
						cout << "Введите три стороны треугольника через пробел." << endl;
						cin >> a >> b >> c;
						triangle_mas[target - 1].set_triangle(a, b, c);
						cout << "Данные заданы" << endl;
						break;

					case 2:
						cout << "Площадь треугольника равна: " << triangle_mas[target - 1].square() << endl;
						break;

					case 3:
						cout << "Периметр треугольника равен: " << triangle_mas[target - 1].perimetr() << endl;
						break;

					/*case 4:

						cout << "Цвет фигуры: " << triangle_mas[target - 1].get_color() << endl;
						break;

					case 5:
						cout << "Введите цвет." << endl;
						cin >> color;
						triangle_mas[target - 1].set_color(color);
						cout << "Цвет фигуры: " << triangle_mas[target - 1].get_color() << endl;
						break;*/
					
					default:
						cout << "Ошибка";
						break;
					}
					cout << endl;
				}
			}
			if(number == 3)
			{	
				for (int i = 0; i < rectangle_mas.size(); i++)
				{	
					cout << "Прямоугольник №: " << i + 1 << endl;
				}

				cout <<  rectangle_mas.size() + 1 << " - Добавить новый прямоугольник" << endl <<
				rectangle_mas.size() + 2 << " - Удалить один из прямоугольников" << endl;
				cout << "Выберите треугольник -> от 1 до " << rectangle_mas.size() << " или функцию. Для выхода из программы введите -> 0." << endl << "-> ";
				
				cin >> target;
				if (target - 1 < 0) break;
				if (target > rectangle_mas.size() + 2)
				{
					cout << "Неверный номер прямоугольника." << endl;
					continue;
				}
				cout << "Вы выбрали № " << target << endl;
				
				if(target == rectangle_mas.size() + 1)
				{
					cout << "Введите две стороны через пробел." << endl;
					cin >> a >> b;
					rectangle_mas.push_back(Rectangle(a, b));
					cout << "Данные заданы" << endl;
					continue;
				}
				if(target == rectangle_mas.size() + 2)
				{
					cout << "Введите номер прямоугольника." << endl;
					cin >> point;
					rectangle_mas.erase(rectangle_mas.begin() + point - 1);
					cout << "Данные заданы" << endl;
					continue;
				}

				while (true)
				{
					cout <<
						"Выберите функцию" << endl <<
						"0 - Выход из программы" << endl <<
						"1 - Задать параметры прямоугольника" << endl <<
						"2 - Посчитать площадь прямоугольника" << endl <<
						"3 - Посчитать периметр прямоугольника" << endl <<
						"4 - Выбрать другую фигуру" << endl <<
						"-> ";
					cin >> func_num;

					if (func_num == 0)
					{
						check = false;
						break;
					}

					if (func_num == 4)
					{
						break;
					}

					switch (func_num)
					{
					case 1:
						cout << "Введите две стороны прямоугольника через пробел." << endl;
						cin >> a >> b;
						rectangle_mas[target - 1].set_rectangle(a, b);
						cout << "Данные заданы" << endl;
						break;

					case 2:
						cout << "Площадь прямоугольника равна: " << rectangle_mas[target - 1].square() << endl;
						break;

					case 3:
						cout << "Периметр прямоугольника равен: " << rectangle_mas[target - 1].perimetr() << endl;
						break;
					
					default:
						cout << "Ошибка";
						break;
					}
					cout << endl;
				}
			}
			if(number == 4)
			{	
				for (int i = 0; i < square_mas.size(); i++)
				{	
					cout << "Квадрат №: " << i + 1 << endl;
				}

				cout <<  square_mas.size() + 1 << " - Добавить новый квадрат" << endl <<
				square_mas.size() + 2 << " - Удалить один из квадратов" << endl;
				cout << "Выберите квадрат -> от 1 до " << square_mas.size() << " или функцию. Для выхода из программы введите -> 0." << endl << "-> ";

				cin >> target;
				if (target - 1 < 0) break;
				if (target > square_mas.size() + 2)
				{
					cout << "Неверный номер квадрата." << endl;
					continue;
				}
				cout << "Вы выбрали № " << target << endl;

				if(target == square_mas.size() + 1)
				{
					cout << "Введите сторону." << endl;
					cin >> a;
					square_mas.push_back(Square(a));
					cout << "Данные заданы" << endl;
					continue;
				}
				if(target == square_mas.size() + 2)
				{
					cout << "Введите номер квадрата." << endl;
					cin >> point;
					square_mas.erase(square_mas.begin() + point - 1);
					cout << "Данные заданы" << endl;
					continue;
				}

				while (true)
				{
					cout <<
						"Выберите функцию" << endl <<
						"0 - Выход из программы" << endl <<
						"1 - Задать параметры квадрата" << endl <<
						"2 - Посчитать площадь квадрата" << endl <<
						"3 - Посчитать периметр квадрата" << endl <<
						"4 - Выбрать другую фигуру" << endl <<
						"-> ";
					cin >> func_num;

					if (func_num == 0)
					{
						check = false;
						break;
					}

					if (func_num == 4)
					{
						break;
					}

					switch (func_num)
					{
					case 1:
						cout << "Введите сторону квадрата." << endl;
						cin >> a;
						square_mas[target - 1].set_square(a);
						cout << "Данные заданы" << endl;
						break;

					case 2:
						cout << "Площадь квадрата равна: " << square_mas[target - 1].square() << endl;
						break;

					case 3:
						cout << "Периметр квадрата равен: " << square_mas[target - 1].perimetr() << endl;
						break;
					
					default:
						cout << "Ошибка";
						break;
					}
					cout << endl;
				}
			}
		}
		else
		{	
			check = false;
			break;
		}
	}

}