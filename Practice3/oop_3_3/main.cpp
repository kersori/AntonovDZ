#include <iostream>
#include "bay.h"
#include "ocean.h"
#include "sea.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Ocean ocean1("Индийский океан", "Азия", 1, 20);
	cout << "Океан ->" << endl;
	cout << ocean1 << endl;
	
	Sea sea1("Красное море", ocean1.get_name(), ocean1.get_area(), 5);
	sea1.add_parent(ocean1);
	cout << "Море ->" << endl;
	cout << sea1 << endl;

	Bay bay1("Красный залив", sea1.get_name(), ocean1.get_area(), 1);
	sea1.add_parent(sea1);
	sea1.add_child(bay1);
	cout << "Залив ->" << endl;
	cout << bay1 << endl;

	Ocean ocean;
	cout << "Введите данные для океана ->" << endl;
	cin >> ocean;
	cout << ocean << endl;
	
	Bay bay;
	cout << "Введите данные для залива ->" << endl;
	cin >> bay;
	cout << bay;
	bay.add_parent(ocean);

	Sea sea;
	cout << "Введите данные для моря ->" << endl;
	cin >> sea;
	cout << sea;
	sea.add_parent(ocean);
	sea.add_child(bay);

	return 0;
}