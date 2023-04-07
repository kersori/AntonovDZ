#include <cmath>
#include <iostream>

class rational
{
private:
	
public:
	int a, b;//числитель и значменатель дроби, натуральные числа, знаменаитель не равен 0
	rational();
	rational(int a1, int b1);//конструктор
	void set(int a1, int b1);//проверка значений и их установка
	void show(int i);//вывод дроби
	int nod(int a, int b);//наибольший общий делитель

protected:

};