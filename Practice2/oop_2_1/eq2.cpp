#define _USE_MATH_DEFINES
#include "eq2.h"

using namespace std;

eq2::eq2(double a1, double b1, double c1) 
{	
	this->D = b1 * b1 - 4 * a1 * c1;
}

void eq2::set(double a1, double b1, double c1) 
{
	this->a = a1;
	this->b = b1;
	this->c = c1;
}

double eq2::find_X()
{
	if(D < 0)
	{
		cout << "Корней нет" << endl;
		return 0;
	}
	else
	{
		if(D == 0)
		{
			cout << "Корень один: ";
			double x = (-b) / (2 * a);
			cout << x << endl;
			return x;
		}
		else
		{
			cout << "Корней два, наибольший: ";
			double x1 = (-b - sqrt(D)) / (2 * a);
			double x2 = (-b + sqrt(D)) / (2 * a);
			if(x1 > x2)
			{
				cout << x1 << endl;
				return x1;
			}
			else
			{
				cout << x2 << endl;
				return x2;
			}
		}
	}
}

double eq2::find_Y(double x1)
{	
	return (a * x1 * x1 + b * x1 + c);
}

void eq2::Out()
{
	cout << "Объект класса: а=" << a << " b=" << b << " c=" << c << endl;
}
