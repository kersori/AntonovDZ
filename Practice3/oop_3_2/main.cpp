#include "currentcone.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Cone parentcone;

	CurrentCone mass[2];

	for (int i = 0; i < 2; i++)
	{
		cout << "Введите r Радиус нижнего основания" << endl
			<< "h Высоту полного конуса " << endl
			<< "r2 Радиус сечения" << endl
			<< "h2 Высоту сечения" << endl
			<< "x, y, z (через пробел)" << endl;
		cin >> mass[i];
		cout << mass[i] << endl;
	}

	cout << endl;
	if (mass[0] > mass[1])
	{
		cout << "cone1 > cone2" << endl;
	}
	if (mass[0] < mass[1])
	{
		cout << "cone1 < cone2" << endl;
	}
	if (mass[0] == mass[1])
	{
		cout << "cone1 == cone2" << endl;
	}

	Cone base(5, 5, 0, 0, 0);

	cout << endl <<"Усеченный конус производный от базового конуса" << endl;
	CurrentCone childcone(base);
	cout << childcone;

	CurrentCone childcone2(base, 1, 2);
	cout << childcone2;


	return 0;
}