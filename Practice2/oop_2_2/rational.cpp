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
	if(b1 != 0)
	{	
		if(a1 > b1)
		{	
			a1 = a1 % b1;
		}

		this->a = (a1/rational::nod(a1, b1));
		this->b = (b1/rational::nod(a1, b1));
	}
	else
	{
		cout << "Знаменатель равен нулю. Ведите корректно дробь: " << endl << "-> ";
		cin >> this->a >> this->b;
		this->set(this->a, this->b);
	}
}

void rational::show(int i) 
{	
	if(this->a != 0)
	{
		cout << "Дробь №" << i << " -> " << this->a << "/" << this->b << endl;
	}
	else
	{
		cout << "Дробь №" << i << " -> " << 0 << endl;
	}
}

int rational::nod(int a1, int b1) 
{	
	while (a1 > 0 && b1 > 0)
	{
		if(a1 > b1)
		{
			a1 %= b1;
		}
		else
		{
			b1 %= a1;
		}
	}
	return a1 + b1;
}