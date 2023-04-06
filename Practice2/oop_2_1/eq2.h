#include <cmath>
#include <iostream>

class eq2
{
private:
	double a, b, c;//коэффициенты уравнения
	double D;//дискриминант, вычисляется внутри конструктора объекта

public:
	eq2(double a1, double b1, double c1);//конструктор
	void set(double a1, double b1, double c1);//занести значения коэф. в объект
	double find_X();//возвращает наибольший корень либо 0 и инф. что корней нет.
	double find_Y(double x1);//возвращает значения квадратного многчлена с заданными коэф. при заданном Х
	eq2 operator+(eq2 exmpl)
	{
		eq2 exmplsum(a, b, c);
		exmplsum.a = this->a + exmpl.a;
		exmplsum.b = this->b + exmpl.b;
		exmplsum.c = this->c + exmpl.c;
		return exmplsum;
	}
	void Out();

protected:

};