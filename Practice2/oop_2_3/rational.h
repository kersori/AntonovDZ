#include <cmath>
#include <iostream>

class rational
{
private:
	int a, b;//числитель и значменатель дроби, натуральные числа, знаменаитель не равен 0
	friend rational operator-(rational& mass1, rational& mass2);//перегрузка вычитания
	friend int operator>(rational& mass1, rational& mass2);//перегрузка сравнения

public:
	rational();
	rational(int a1, int b1);//конструктор
	void set(int a1, int b1);//проверка значений и их установка
	void show(int i);//вывод дроби
	int nod(int a, int b);//наибольший общий делитель
	int nok(int a, int b);//наименьший общее кратное
	rational operator+(rational& mass);//перегрузка сложения
	int out1();//вывод результата
	int out2();//вывод результата
	rational& operator++(const int);//перегрузка инкремента
	bool operator==(rational& mass);//перегрузка сравнения
	rational& operator=(rational const& mass);//перегрузка присвоения

protected:

};