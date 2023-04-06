#define _USE_MATH_DEFINES
#include "figure.h"


using namespace std;

figure::figure(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4) {
	this->x1 = x1;
	this->x2 = x2;
	this->x3 = x3;
	this->x4 = x4;
	this->y1 = y1;
	this->y2 = y2;
	this->y3 = y3;
	this->y4 = y4;

	P = sqrt(pow(this->x1 - this->x2, 2) + pow(this->y1 - this->y2, 2)) +
		sqrt(pow(this->x2 - this->x3, 2) + pow(this->y2 - this->y3, 2)) +
		sqrt(pow(this->x3 - this->x4, 2) + pow(this->y3 - this->y4, 2)) +
		sqrt(pow(this->x4 - this->x1, 2) + pow(this->y4 - this->y1, 2));

	float P1, P2;
	float AB1, BC1, CD1, AD1, AC1;

	AB1 = sqrt(pow(this->x1 - this->x2, 2) + pow(this->y1 - this->y2, 2));
	BC1 = sqrt(pow(this->x2 - this->x3, 2) + pow(this->y2 - this->y3, 2));
	CD1 = sqrt(pow(this->x3 - this->x4, 2) + pow(this->y3 - this->y4, 2));
	AD1 = sqrt(pow(this->x1 - this->x4, 2) + pow(this->y1 - this->y4, 2));
	AC1 = sqrt(pow(this->x1 - this->x3, 2) + pow(this->y1 - this->y3, 2));

	P1 = AB1 + BC1 + AC1;
	P2 = AC1 + CD1 + AD1;

	S = sqrt((P1/2) * ((P1/2) - AB1) * ((P1/2) - BC1) * ((P1/2) - AC1)) +
		sqrt((P2/2) * ((P2/2) - AC1) * ((P2/2) - CD1) * ((P2/2) - AD1));
}
void figure::show() {
	cout << "Координаты вершины четырехугольника: A(" << x1 << "," << y1 << ") " << "B(" << x2 << ", " << y2 << ") " << "C(" << x3 << ", " << y3 << ") " << "D(" << x4 << ", " << y4 << ") " << endl;
	cout << "Периметр четырехугольника: " << P << endl;
	cout << "Площадь четырехугольника: " << S << endl;
}
bool figure::is_prug() {
	if (abs(sqrt(pow(this->x1 - this->x3, 2) + pow(this->y1 - this->y3, 2)) - sqrt(pow(this->x2 - this->x4, 2) + pow(this->y2 - this->y4, 2))) < 0.1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool figure::is_square() {
	if (is_romb() && is_prug())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool figure::is_romb() {
	if ((abs(sqrt(pow(this->x1 - this->x2, 2) + pow(this->y1 - this->y2, 2)) - sqrt(pow(this->x2 - this->x3, 2) + pow(this->y2 - this->y3, 2))) < 0.1) &&
		(abs(sqrt(pow(this->x2 - this->x3, 2) + pow(this->y2 - this->y3, 2)) - sqrt(pow(this->x3 - this->x4, 2) + pow(this->y3 - this->y4, 2))) < 0.1) &&
		(abs(sqrt(pow(this->x3 - this->x4, 2) + pow(this->y3 - this->y4, 2)) - sqrt(pow(this->x4 - this->x1, 2) + pow(this->y4 - this->y1, 2))) < 0.1))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool figure::is_in_circle() {
	float AB, BC, CD, AD;
	AB = sqrt(pow(this->x1 - this->x2, 2) + pow(this->y1 - this->y2, 2));
	BC = sqrt(pow(this->x2 - this->x3, 2) + pow(this->y2 - this->y3, 2));
	CD = sqrt(pow(this->x3 - this->x4, 2) + pow(this->y3 - this->y4, 2));
	AD = sqrt(pow(this->x4 - this->x1, 2) + pow(this->y4 - this->y1, 2));
	if (abs((AB + CD) - (BC + AD)) < 0.1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool figure::is_out_circle() {
	float v1x = this->x2 - this->x1;
	float v1y = this->y2 - this->y1;
	float v2x = this->x4 - this->x1;
	float v2y = this->y4 - this->y1;
	float v3x = this->x3 - this->x2;
	float v3y = this->y3 - this->y2;

	float v1 = sqrt(pow(v1x, 2) + pow(v1y, 2));
	float v2 = sqrt(pow(v2x, 2) + pow(v2y, 2));
	float v3 = sqrt(pow(v3x, 2) + pow(v3y, 2));

	float vec1 = v1x * v2x + v1y * v2y;
	float vec2 = v2x * v3x + v2y * v3y;

	float alpha = acos(vec1 / (v1 * v2));
	float beta = acos(vec2 / (v2 * v3));

	if (abs(M_PI / 2 - alpha - beta) < 0.1)
	{
		return true;
	}
	else
	{
		return false;
	}
}