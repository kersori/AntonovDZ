#define _USE_MATH_DEFINES
#include "rational.h"

using namespace std;

rational::rational(int a1, int b1)
{
	a = a1;
	b = b1;
}

rational::rational()
{

}

void rational::set(int a1, int b1)
{
	if (b1 != 0)
	{
		if (a1 > b1)
		{
			a1 = a1 % b1;
		}

		this->a = (a1 / rational::nod(a1, b1));
		this->b = (b1 / rational::nod(a1, b1));
	}
	else
	{
		cout << "Знаменатель равен нулю. Введите корректно дробь: " << endl << "-> ";
		cin >> this->a >> this->b;
		this->set(this->a, this->b);
	}
}

void rational::show(int i)
{
	if (this->a != 0)
	{
		cout << endl << "Дробь №" << i + 1 << " -> " << this->a << "/" << this->b << endl;
	}
	else
	{
		cout << endl << "Дробь №" << i + 1 << " -> " << 0 << endl;
	}
}

int rational::nod(int b1, int b2)
{
	while (b1 > 0 && b2 > 0)
	{
		if (b1 > b2)
		{
			b1 %= b2;
		}
		else
		{
			b2 %= b1;
		}
	}
	return b1 + b2;
}

int rational::nok(int b1, int b2)
{
	int max = b1;
	for (int i = max; i > 0; i++)
	{
		if ((i % b1 == 0) && (i % b2 == 0))
		{
			return i;
		}
	}
}

int rational::out1()
{
	return this->a;
}
int rational::out2()
{
	return this->b;
}

rational rational::operator+(rational& mass)
{
	rational mass1;
	mass1.b = nok(this->b, mass.b);
	mass1.a = (this->a) * (mass1.b / this->b) + (mass.a) * (mass1.b / mass.b);
	return mass1;
}

rational operator-(rational& mass1, rational& mass2)
{
	rational masstemp;
	masstemp.b = masstemp.nok(mass1.b, mass2.b);
	masstemp.a = (mass1.a) * (masstemp.b / mass1.b) - (mass2.a) * (masstemp.b / mass2.b);
	return masstemp;
}

rational& rational::operator++(const int)
{
	rational& tmp = *this;
	a++;
	return tmp;
}

bool rational::operator==(rational& mass)
{
	return (mass.a == this->a && mass.b == this->b);
}

int operator>(rational& mass1, rational& mass2)
{
	rational tmp;
	rational tmp2;
	tmp.b = tmp.nok(mass1.b, mass2.b);
	tmp2.a = tmp.b / mass1.a;
	tmp2.b = tmp.b / mass2.a;

	return tmp2.a < tmp2.b;
}
rational& rational::operator=(rational const& mass)
{	
	this->a = mass.a;
	this->b = mass.b;
	return *this;
}
