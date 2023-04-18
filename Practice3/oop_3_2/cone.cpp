#include "cone.h"

using namespace std;

Cone::Cone()
{
	x = y = z = 0;
	height = radius = 1;
}

Cone::Cone(double r, double h)
{
	x = y = z = 0;
	height = h;
	radius = r;
}

Cone::Cone(double r, double h, double x1, double y1, double z1)
{
	x = x1;
	y = y1;
	z = z1;
	height = h;
	radius = r;
}

void Cone::setRadius(double r)
{
	radius = r;
}

void Cone::setHeight(double h)
{
	height = h;
}

void Cone::setCoordinate(double x1, double y1, double z1)
{
	x = x1;
	y = y1;
	z = z1;
}

double Cone::area()
{
	return (3.14 * radius * (radius + sqrt(pow(radius, 2) + pow(height, 2))));
}

double Cone::volume()
{
	return (3.14 * pow(radius, 2) * height) / 3;
}

void Cone::show()
{
	setlocale(LC_ALL, "Russian");
	cout << "Координаты конуса x = " << x << "; y = " << y << "; z = " << z << "; " << endl;
	cout << "Высота конуса h: " << height << endl;
	cout << "Радиус конуса r: " << radius;
}

double Cone::getHeight()
{
	return height;
}

double Cone::getRadius()
{
	return radius;
}

double Cone::getX()
{
	return x;
}

double Cone::getY()
{
	return y;
}

double Cone::getZ()
{
	return z;
}