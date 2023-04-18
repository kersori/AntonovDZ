#include "cone.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Cone c1(15, 5);
	c1.show();
	cout << endl << endl;

	Cone c2(3, 5, 1, 1, 1);
	c2.show();
	cout << endl << endl;

	cout << "Конус 1" << c1;
	cout << "Площадь поверхности = " << c1.area() << ";" << endl;
	cout << "Объем = " << c1.volume()<< endl;
	cout << "Конус 2" << c2;
	cout << "Площадь поверхности = " << c2.area() << ";" << endl;
	cout << "Объем = " << c2.volume()<< endl;

	double h, r, x, y, z;

	int in;
	int infunc;
	bool check = true;

	Cone* conusmass[3];

	cout << endl << endl;
	for(int i = 0; i < 3; i++)
	{
		cout << "Введите данные для трех конусов ->" << endl;
		cout << "Введите данные для конуса №" << i + 1 << " (через пробел r, h, x, y, z)" << endl;
		cin >> r >> h >> x >> y >> z;
		conusmass[i]->setCoordinate(x, y, z);
		conusmass[i]->setRadius(r);
		conusmass[i]->setHeight(h);
	}

	while (true)
	{
		cout << "Введите номер конуса или 0 для выхода." << endl << "->";
		cin >> in;
		in -= 1;

		if (in < -1 || in > 2)
		{
			cout << "Ошибка";
			continue;
		}

		if (in == -1)
		{
			break;
		}

		while (check)
		{
			cout << "Ввведите номер функции" << endl
			<< "0 -> Выход" << endl
			<< "1 -> Изменить данные конуса" << endl
			<< "2 -> Отобразить параметры конуса" << endl
			<< "3 -> Площадь конуса" << endl
			<< "4 -> Объём конуса" << endl << "->";
			cin >> infunc;

			switch (infunc)
			{
			case 0:
				check = false;
				break;

			case 1:
				while (true)
				{	
					cout << "Выберите какие данные изменить" << endl
					<< "0 -> Выход" << endl
					<< "1 -> Только h" << endl
					<< "2 -> Только r" << endl
					<< "3 -> Только x, y, z" << endl << "->";
					cin >> infunc;

					if (infunc == 1 || infunc == 2 || infunc == 3)
					{
						break;
					}
					cout << "Неверно" << endl;
				}

				switch (infunc)
				{
				case 1:
					cout << "Ввведите h для " << in + 1 << "-го конуса" << endl;
					cin >> h;
					conusmass[in]->setHeight(h);
					break;

				case 2:
					cout << "Ввведите r для " << in + 1 << "-го конуса" << endl;
					cin >> r;
					conusmass[in]->setRadius(r);
					break;

				case 3:
					cout << "Ввведите x, y, z для " << in + 1 << "-го конуса" << endl;
					cin >> x >> y >> z;

					conusmass[in]->setCoordinate(x, y, z);
					break;
				}
				break;

			case 2:
				conusmass[in]->show();
				break;

			case 3:
				cout << "Площадь: " << conusmass[in]->area() << endl;
				break;

			case 4:
				cout << "Объем: " << conusmass[in]->volume();
				break;
			}
			cout << endl << endl;
		}

	}

	return 0;
}